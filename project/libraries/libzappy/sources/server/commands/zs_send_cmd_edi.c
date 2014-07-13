/*
** zs_send_cmd_edi.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sat Jul 12 16:38:31 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_edi(t_zs *this, t_zc *zc, unsigned int eid)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "edi %u\n", eid);
  zs_send(this, zc, buf);
}
