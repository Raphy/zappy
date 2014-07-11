/*
** list_insert.c for liblist in /home/raphy/Epitech/Tech_2/zappy/project/libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jul 11 16:40:42 2014 raphael defreitas
** Last update Fri Jul 11 16:58:28 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

static void	instert_before_ref(t_list *this, t_item *ref, t_item *item)
{
  item->next = ref;
  item->prev = ref->prev;
  if (ref->prev)
    ref->prev->next = item;
  ref->prev = item;
  if (this->front == ref)
    this->front = item;
}

static void	instert_after_ref(t_list *this, t_item *ref, t_item *item)
{
  item->next = ref->next;
  item->prev = ref;
  if (ref->next)
    ref->next->prev = item;
  ref->next = item;
  if (this->back == ref)
    this->back = item;
}

int		list_insert(t_list *this, t_item *ref, void *data, int dir)
{
  t_item	*item;

  if (this == NULL || ref == NULL || dir == 0)
    return (RET_FAILURE);
  if ((item = item_new(data, this->data_free_fptr)) == NULL)
    return (RET_FAILURE);
  if (dir > 0)
    insert_after_ref(this, ref, item);
  else
    instert_before_ref(this, ref, item);
  this->length++;
  return (RET_SUCCESS);
}
