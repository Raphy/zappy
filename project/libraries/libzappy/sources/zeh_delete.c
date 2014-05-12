/*
** zeh_delete.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 14:26:15 2014 raphael defreitas
** Last update Mon May 12 14:39:46 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zeh_delete(t_zeh *this)
{
  zeh_dtor(this);
  free(this);
}
