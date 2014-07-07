/*
** zs_send_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Mon Jul  7 17:59:43 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_bct(t_zs *this, t_zc *zc, t_bct *bct)
{
  char		buf[150];

  if (this == NULL)
    return ;
  sprintf(buf, "bct %u %u %u %u %u %u %u %u %u\n", bct->position.x,
	  bct->position.y, bct->food, bct->linemate, bct->deraumere, bct->sibur,
	  bct->mendiane, bct->phiras, bct->thystame);
  zs_send(this, zc, buf);
}
