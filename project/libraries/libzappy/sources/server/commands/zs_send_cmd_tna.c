/*
** zs_send_cmd_tna.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Wed Jul  9 18:46:19 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_tna(t_zs *this, t_zc *zc, const char *tna)
{
  if (this == NULL)
    return ;
  zs_send(this, zc, "tna ");
  zs_send(this, zc, tna);
  zs_send(this, zc, "\n");
}
