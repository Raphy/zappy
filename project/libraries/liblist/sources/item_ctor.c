/*
** item_ctor.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:16:49 2014 raphael defreitas
** Last update Thu Apr 17 20:28:06 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

int		item_ctor(t_item *this, void *data, void (*data_free_fptr)())
{
  this->data = data;
  this->prev = NULL;
  this->next = NULL;
  this->data_free_fptr = data_free_fptr;
  return (RET_SUCCESS);
}
