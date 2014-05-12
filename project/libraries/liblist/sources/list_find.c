/*
** list_find.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 20:42:12 2014 raphael defreitas
** Last update Mon Apr 21 01:10:30 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*list_find(t_list *this, int (*find_fptr)(), const void *srch,
			   t_it_type type)
{
  t_iterator	iterator;
  t_item	*item;

  iterator_ctor(&iterator, this, IT_ITEM);
  while ((item = iterator_current(&iterator)))
    {
      iterator_next(&iterator);
      if (find_fptr(item_data(item), srch) == 0)
	return (type == IT_ITEM ? item : item_data(item));
    }
  return (NULL);
}
