/*
** list_clear.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 16:07:35 2014 raphael defreitas
** Last update Sun Jun 29 08:52:37 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		list_clear(t_list *this)
{
  t_iterator	iterator;
  t_item	*item;

  iterator_ctor(&iterator, this, IT_ITEM);
  while ((item = iterator_current(&iterator)))
    {
      iterator_next(&iterator);
      item_delete(item);
    }
  iterator_dtor(&iterator);
  this->length = 0;
}
