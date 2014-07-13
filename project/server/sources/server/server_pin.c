/*
** server_pin.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 16:02:38 2014 damien sauvalle
** Last update Sat Jul 12 18:01:14 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"
#include	"player.h"

void		server_pin(t_zs *zs, t_zc *zc, unsigned int nbr, void *d)
{
  t_player	*player;
  t_pin		pin;

  player = list_find(((t_server *)d)->players, &find_by_uid, &nbr, IT_DATA);
  if (player != NULL)
    {
      pin.uid = zc_get_uid(player->zc);
      pin.position.x = player->x;
      pin.position.y = player->y;
      pin.items = player->inventory;
      zs_send_cmd_pin(zs, zc, &pin);
    }
  else
    zs_send_cmd_sbp(zs, zc);
}
