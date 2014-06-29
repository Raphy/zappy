/*
** list_dtor.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:41:19 2014 raphael defreitas
** Last update Sun Jun 29 06:30:35 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		list_dtor(t_list *this)
{
  t_iterator	iterator;
  t_item	*item;

  if (this == NULL)
    return ;
  iterator_ctor(&iterator, this, IT_ITEM);
  while ((item = iterator_current(&iterator)))
    {
      iterator_next(&iterator);
      item_delete(item);
    }
}
