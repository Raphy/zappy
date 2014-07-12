/*
** zs_send_death.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sun Jul 13 00:41:01 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_death(t_zs *this, t_zc *zc)
{
  if (this == NULL)
    return ;
  zs_send(this, zc, "mort\n");
}
