/*
** zs_send_cmd_pie.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sat Jul 12 12:24:10 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_pie(t_zs *this, t_zc *zc, const t_pie *pie)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "pie %u %u %u\n", pie->position.x, pie->position.y,
	  pie->result ? 1 : 0);
  zs_send(this, zc, buf);
}
