/*
** list_enqueue.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:56:37 2014 raphael defreitas
** Last update Sat Apr 19 02:31:23 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

int		list_enqueue(t_list *this, void *data)
{
  t_item	*item;

  if ((item = item_new(data, this->data_free_fptr)) == NULL)
    return (RET_FAILURE);
  item->prev = this->back;
  if (this->back)
    this->back->next = item;
  else
    this->back = item;
  if (!this->front)
    this->front = item;
  this->back = item;
  this->length++;
  return (RET_SUCCESS);
}
