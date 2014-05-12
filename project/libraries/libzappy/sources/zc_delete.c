/*
** zc_delete.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 16:41:25 2014 raphael defreitas
** Last update Mon May 12 16:41:53 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zc_delete(t_zc *this)
{
  zc_dtor(this);
  free(this);
}
