/*
** zs_send_cmd_msz.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sun Jul 13 00:24:13 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_msz(t_zs *this, t_zc *zc, const t_msz *msz)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "msz %u %u\n", msz->width, msz->height);
  zs_send(this, zc, buf);
}
