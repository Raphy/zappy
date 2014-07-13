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

static bool test(void *data, void *searched)
{
  return (data == searched);
}

void		player_action_goahead(t_zc *zc, void *data)
{
  fct_direction	tab[5];
  t_item        *item;
  t_bundle      *bundle;
  
  tab[1] = go_north;
  tab[2] = go_est;
  tab[3] = go_south;
  tab[4] = go_west;
  bundle = (t_bundle *)data;
  item = list_find(&(bundle->server->map[bundle->player->y][bundle->player->x]).players, &test, bundle->player, IT_ITEM);
  if (item != NULL)
    printf("YOUPI! [%d]\n", item_data(item) == bundle->player);
  list_unlink(&(bundle->server->map[bundle->player->y][bundle->player->x]).players, item);
  if (bundle->player->direction < 5 && bundle->player->direction > 0)
  {
    printf("Je mouve!\n");
    tab[bundle->player->direction](bundle);
  }
  list_push(&(bundle->server->map[bundle->player->y][bundle->player->x].players), bundle->player);
  server_send_ppo_all_graphic(bundle);
  zs_send_ok(bundle->server->zs, bundle->player->zc);
}
