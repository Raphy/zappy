/*
** zs_delete.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 15:49:34 2014 raphael defreitas
** Last update Mon May 12 15:50:32 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zs_delete(t_zs *this)
{
  free(this);
}
