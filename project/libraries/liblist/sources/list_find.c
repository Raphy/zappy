/*
** list_find.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 20:42:12 2014 raphael defreitas
** Last update Sat Jul 12 13:18:25 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>

#include	"list.h"

void		*list_find(t_list *this, bool (*finder)(), const void *searched,
			   t_it_type type)
{
  t_iterator	iterator;
  t_item	*item;

  if (this == NULL || finder == NULL)
    return (NULL);
  iterator_ctor(&iterator, this, IT_ITEM);
  while ((item = iterator_current(&iterator)))
    {
      iterator_next(&iterator);
      if (finder(item_data(item), searched))
	return (type == IT_ITEM ? item : item_data(item));
    }
  return (NULL);
}
