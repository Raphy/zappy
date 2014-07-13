/*
** player_action_pick.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 17:49:12 2014 damien sauvalle
** Last update Sun Jul 13 15:25:26 2014 damien sauvalle
*/

#include	<stdio.h>

#include	"player.h"
#include	"bundle.h"
#include	"zappy.h"

void	player_action_pick(t_player *player, void *data)
{
  (void)player;
  t_bundle *bundle;

  if ((bundle = data) == NULL || bundle->server == NULL)
    return ;

  t_position pos;
  t_items inv;

  pos.x = bundle->player->x;
  pos.y = bundle->player->y;

  inv = bundle->server->map[pos.y][pos.x].inventory;



}
