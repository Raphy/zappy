/*
** list_dequeue.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 16:07:35 2014 raphael defreitas
** Last update Sun Jun 29 06:33:00 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*list_dequeue(t_list *this)
{
  void		*data;

  if (this == NULL)
    return (NULL);
  if (this->back == NULL)
    return (NULL);
  data = item_data(this->back);
  list_unlink(this, this->back);
  return (data);
}
