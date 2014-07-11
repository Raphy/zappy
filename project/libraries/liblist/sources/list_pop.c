/*
** list_pop.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 16:07:35 2014 raphael defreitas
** Last update Fri Jul 11 17:00:23 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*list_pop(t_list *this)
{
  void		*data;

  if (this == NULL)
    return (NULL);
  if (this->front == NULL)
    return (NULL);
  data = item_data(this->front);
  list_unlink(this, this->front);
  return (data);
}
