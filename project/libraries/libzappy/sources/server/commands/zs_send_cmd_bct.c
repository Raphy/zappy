/*
** zs_send_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Thu Jul 10 01:56:38 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_bct(t_zs *this, t_zc *zc, const t_bct *bct)
{
  char		buf[150];

  if (this == NULL)
    return ;
  sprintf(buf, "bct %u %u %u %u %u %u %u %u %u\n", bct->position.x,
	  bct->position.y, bct->items.food, bct->items.linemate,
	  bct->items.deraumere, bct->items.sibur, bct->items.mendiane,
	  bct->items.phiras, bct->items.thystame);
  zs_send(this, zc, buf);
}
