/*
** server_ppo.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 13:03:29 2014 damien sauvalle
** Last update Sat Jul 12 18:00:28 2014 damien sauvalle
*/

#include	<stdio.h>
#include	"server.h"
#include	"zappy.h"
#include	"player.h"


void	server_ppo(t_zs *zs, t_zc *zc, unsigned int nbr, void *d)
{
  t_player *player;
  t_ppo ppo;

  player = list_find(((t_server *)d)->players, &find_by_uid, &nbr, IT_DATA);
  if (player != NULL)
    {
      ppo.uid = zc_get_uid(player->zc);
      ppo.position.x = player->x;
      ppo.position.y = player->y;
      ppo.orientation = player->direction;
      zs_send_cmd_ppo(zs, zc, &ppo);
    }
  else
    zs_send_cmd_sbp(zs, zc);
}
