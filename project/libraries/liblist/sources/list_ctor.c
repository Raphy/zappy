/*
** list_ctor.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:39:24 2014 raphael defreitas
** Last update Sun Apr 20 01:54:52 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

int		list_ctor(t_list *this, void (*data_free_fptr)())
{
  this->front = NULL;
  this->back = NULL;
  this->length = 0;
  this->data_free_fptr = data_free_fptr;
  return (RET_SUCCESS);
}
