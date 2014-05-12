/*
** list_front.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:49:22 2014 raphael defreitas
** Last update Thu Apr 17 19:54:43 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*list_front(t_list *this)
{
  if (this->front)
    return (item_data(this->front));
  return (NULL);
}
