/*
** zs_send_cmd_enw.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sat Jul 12 13:09:53 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_enw(t_zs *this, t_zc *zc, const t_enw *enw)
{
  char		buf[100];

  if (this == NULL)
    return ;
  sprintf(buf, "enw %u %u %u %u\n", enw->eid, enw->uid, enw->position.x,
	  enw->position.y);
  zs_send(this, zc, buf);
}
