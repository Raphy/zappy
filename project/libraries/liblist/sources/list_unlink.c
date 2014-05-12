/*
** list_unlink.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 20:29:00 2014 raphael defreitas
** Last update Sat Apr 19 02:48:28 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*list_unlink(t_list *this, t_item *item)
{
  void		*data;

  data = item->data;
  if (this->front == item)
    this->front = item->next;
  if (this->back == item)
    this->back = item->prev;
  if (item->prev)
    item->prev->next = item->next;
  if (item->next)
    item->next->prev = item->prev;
  free(item);
  this->length--;
  return (data);
}
