/*
** player_ctor.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 19:39:50 2014 damien sauvalle
** Last update Fri Jul  4 15:18:40 2014 damien sauvalle
*/

#include        <assert.h>
#include	<time.h>
#include	<stdlib.h>
#include	"my.h"
#include	"player.h"

int	player_ctor(t_player *player)
{
  assert(player != NULL);
  if (inventory_ctor(&(player->inventory)) == RET_FAILURE)
    return (RET_FAILURE);
  player->direction = rand()%4;
  player->x = rand()%10; /* Voir avec la taille de la map */
  player->y = rand()%10; /* Voir avec la taille de la map */
  player->team_name = NULL; /* Voir avec les params*/
  player->level = 1;
  player->life = player_set_life(player);
  return (RET_SUCCESS);
}
