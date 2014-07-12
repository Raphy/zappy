/*
** zs_send_cmd_eht.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sat Jul 12 13:22:41 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_eht(t_zs *this, t_zc *zc, unsigned int eid)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "eht %u\n", eid);
  zs_send(this, zc, buf);
}
