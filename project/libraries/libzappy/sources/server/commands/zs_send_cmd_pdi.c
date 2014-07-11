/*
** zs_send_cmd_pdi.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sat Jul 12 00:18:05 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_pdi(t_zs *this, t_zc *zc, unsigned int uid)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "pdi %u\n", uid);
  zs_send(this, zc, buf);
}
