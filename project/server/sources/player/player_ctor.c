/*
** player_ctor.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 19:39:50 2014 damien sauvalle
** Last update Thu Jul 10 14:50:47 2014 damien sauvalle
*/

#include	<stdio.h>

#include	<time.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"player.h"
#include	"server.h"
#include	"zappy.h"

int	player_ctor(t_player *player, t_server *server, t_zc *zc, char *team)
{

  printf("JOUER CREE\n");

  if (inventory_ctor(&(player->inventory)) == RET_FAILURE)
    return (RET_FAILURE);
  player->direction = rand()%4;
  player->x = rand()%server->arg->x_world;
  player->y = rand()%server->arg->y_world;
  if ((player->team_name = strdup(team)) == NULL)
    return (RET_FAILURE);
  player->level = 1;
  player->life = player_set_life(player);
  player->etat = NORMAL;
  player->zc = zc;
  return (RET_SUCCESS);
}
