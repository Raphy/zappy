/*
** iterator_ctor.c for liblist in /home/raphy/Epitech/Tech_2/PSU_2013_myirc/libs/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Apr 20 01:56:52 2014 raphael defreitas
** Last update Sun Jun 29 06:25:23 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

int		iterator_ctor(t_iterator *this, t_list *list, t_it_type type)
{
  if (this == NULL)
    return (RET_FAILURE);
  this->list = list;
  this->type = type;
  this->current = list->front;
  return (RET_SUCCESS);
}
