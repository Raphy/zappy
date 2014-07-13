/*
** player_action_broacast.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 17:50:57 2014 damien sauvalle
** Last update Sat Jul  5 17:51:04 2014 damien sauvalle
*/

#include	"player.h"
#include "bundle.h"
#include      "list.h"
#include  "tools_broadcast.h"


/*
 *  1 2  3
 *  4 X5 6
 *  7 8  9
 */

static const char map[9][3][2] =
  {
    {
      {0, 0},
      {0, 0},
      {0, 0}
    },
    {
      {-1, -1},
      {0, -1},
      {1, -1}
    },
    {
      {-1, 0},
      {-1, -1},
      {0, 1}
    },
    {
      {-1, -1},
      {-1, 0},
      {-1, 1}
    },
    {
      {-1, 0},
      {-1, 1},
      {0, 1}
    },
    {
      {-1, 1},
      {0, 1},
      {1, 1}
    },
    {
      {0, 1},
      {1, 1},
      {1, 0}
    },
    {
      {1, -1},
      {1, 0},
      {1, 1}
    },
    {
      {1, 0},
      {1, -1},
      {0, -1}
    },
  };

static int     broadcast(t_position *pos1, t_position *pos2, int map_x, int map_y)
{
  int           solution;
  double        distance[4];
  int           index;
  int           i;

  index = tools_get_case(pos1->x, pos1->y, map_x / 2, map_y / 2);
  i = -1;
  while (++i < 3)
    distance[i] = tools_get_distance(pos1->x, pos1->y,
            pos2->x + map[index][i][0] * map_x,
            pos2->y + map[index][i][1] * map_y);
  i = 0;
  while (++i < 3)
    if (distance[i] < distance[solution])
      solution = i;
  if (distance[solution] > tools_get_distance(pos1->x, pos1->y,
          pos2->x, pos2->y))
    return (tools_get_case(pos1->x, pos1->y, pos2->x, pos2->y));
  return (tools_get_case(pos1->x, pos1->y,
          pos2->x + map[index][solution][0] * map_x,
          pos2->y + map[index][solution][1] * map_y));
}

static void     broadcast_all(int x, int y, t_list *players, t_position *map)
{
  t_iterator    it;
  t_player      *player;
  t_position    pos1;
  t_position    pos2;
  int           result;
  
  iterator_ctor(&it, players, IT_DATA);
  pos1.x = x;
  pos1.y = y;
  while ((player = iterator_current(&it)) != NULL)
  {
    pos2.x = player->x;
    pos2.y = player->y;
    result = broadcast(&pos1, &pos2, map->x, map->y);
    printf("Broadcast: %d\n", result);
    iterator_next(&it);
  }
}

void player_action_broacast(t_player *player, void *data)
{
  t_bundle  *bundle;
  t_position  map;
  
  if ((bundle = data) == NULL || player == NULL || bundle->server == NULL)
    return;
  map.x = bundle->server->arg->x_world;
  map.y = bundle->server->arg->y_world;
  broadcast_all(player->x, player->y, bundle->server->players, &map);
}
