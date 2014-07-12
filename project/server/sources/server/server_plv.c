/*
** server_plv.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 16:02:38 2014 damien sauvalle
** Last update Sat Jul 12 18:00:49 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"
#include	"player.h"

void		server_plv(t_zs *zs, t_zc *zc, unsigned int nbr, void *d)
{
  t_player	*player;
  t_plv		plv;

  player = list_find(((t_server *)d)->players, &find_by_uid, &nbr, IT_DATA);

  if (player != NULL)
    {
      plv.uid = zc_get_uid(player->zc);
      plv.level = player->level;
      zs_send_cmd_plv(zs, zc, &plv);
    }
  else
    zs_send_cmd_sbp(zs, zc);
}
