/*
** item_delete.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 20:00:14 2014 raphael defreitas
** Last update Thu Apr 17 20:27:55 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		item_delete(t_item *this)
{
  item_dtor(this);
  free(this);
}
