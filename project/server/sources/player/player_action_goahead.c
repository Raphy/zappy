/*
** player_action_goahead.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 16:54:55 2014 damien sauvalle
** Last update Sat Jul 12 01:32:49 2014 damien sauvalle
*/

#include	<stdio.h>
#include	"player.h"
#include	"bundle.h"

static void	go_north(t_player * player, t_arg *arg)
{
  if (player->y == 0)
    player->y = arg->y_world - 1;
  else
    player->y--;
}

static void	go_est(t_player * player, t_arg *arg)
{
  if (player->x == arg->x_world - 1)
    player->x = 0;
  else
    player->x++;
}
static void	go_south(t_player * player, t_arg *arg)
{
  if (player->y == arg->y_world - 1)
    player->y = 0;
  else
    player->y++;
}

static void	go_west(t_player * player, t_arg *arg)
{
  if (player->x == 0)
    player->x = arg->x_world - 1;
  else
    player->x--;
}

void		player_action_goahead(t_player *player, t_bundle *data)
{
  fct_direction	tab[5];
  
  tab[1] = go_north;
  tab[2] = go_est;
  tab[3] = go_south;
  tab[4] = go_west;
  if (player->direction < 5 && player->direction > 0)
    tab[player->direction](player, data->server->arg);
}