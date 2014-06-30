/*
** zc_delete.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:50:28 2014 raphael defreitas
** Last update Mon Jun 30 14:29:18 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zc_delete(t_zc *this)
{
  zc_dtor(this);
  free(this);
}
