/*
** zs_send_cmd_pnw.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Thu Jul 10 01:11:20 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_pnw(t_zs *this, t_zc *zc, const t_pnw *pnw)
{
  char		buf[100];

  if (this == NULL)
    return ;
  sprintf(buf, "pnw %u %u %u %u %u ", pnw->uid, pnw->position.x,
	  pnw->position.y, pnw->orientation, pnw->level);
  zs_send(this, zc, buf);
  zs_send(this, zc, pnw->team_name);
  zs_send(this, zc, "\n");
}
