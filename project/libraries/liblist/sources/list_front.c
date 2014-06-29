/*
** list_front.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:49:22 2014 raphael defreitas
** Last update Sun Jun 29 06:26:59 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*list_front(t_list *this)
{
  if (this == NULL)
    return (NULL);
  if (this->front)
    return (item_data(this->front));
  return (NULL);
}
