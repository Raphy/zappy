/*
** player_action_goahead.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 16:54:55 2014 damien sauvalle
** Last update Sun Jul 13 03:14:32 2014 damien sauvalle
*/

#include	"player.h"
#include	"player_action.h"
#include	"zappy.h"

static void	go_north(t_bundle *data)
{
  if (data->player->y == 0)
    data->player->y = data->server->arg->y_world - 1;
  else
    data->player->y--;
}

static void	go_est(t_bundle *data)
{
  if (data->player->x == data->server->arg->x_world - 1)
    data->player->x = 0;
  else
    data->player->x++;
}

static void	go_south(t_bundle *data)
{
  if (data->player->y == data->server->arg->y_world - 1)
    data->player->y = 0;
  else
    data->player->y++;
}

static void	go_west(t_bundle *data)
{
  if (data->player->x == 0)
    data->player->x = data->server->arg->x_world - 1;
  else
    data->player->x--;
}

void		player_action_goahead(t_player *player, void *data)
{
  fct_direction	tab[4];
  unsigned int	i;
  t_bundle	*bundle;

  (void)player;
  bundle = (t_bundle *)data;
  tab[0] = go_north;
  tab[1] = go_est;
  tab[2] = go_south;
  tab[3] = go_west;
  i = 0;
  while (i < 4)
    {
      if (i == bundle->player->direction)
	tab[i](bundle);
      i++;
    }
  server_send_ppo_all_graphic(bundle);
  zs_send_ok(bundle->server->zs, bundle->player->zc);
}
