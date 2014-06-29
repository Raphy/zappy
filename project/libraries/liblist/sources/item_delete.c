/*
** item_delete.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 20:00:14 2014 raphael defreitas
** Last update Sun Jun 29 06:28:46 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		item_delete(t_item *this)
{
  if (this == NULL)
    return ;
  item_dtor(this);
  free(this);
}
