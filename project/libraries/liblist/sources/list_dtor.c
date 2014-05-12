/*
** list_dtor.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:41:19 2014 raphael defreitas
** Last update Sun Apr 20 02:03:52 2014 raphael defreitas
*/

#include	"list.h"

void		list_dtor(t_list *this)
{
  t_iterator	iterator;
  t_item	*item;

  iterator_ctor(&iterator, this, IT_ITEM);
  while ((item = iterator_current(&iterator)))
    {
      iterator_next(&iterator);
      item_delete(item);
    }
}
