/*
** iterator_current.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:25:07 2014 raphael defreitas
** Last update Thu Apr 17 19:48:23 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*iterator_current(t_iterator *this)
{
  if (this->current && this->type == IT_ITEM)
    return (this->current);
  if (this->current && this->type == IT_DATA)
    return (item_data(this->current));
  return (NULL);
}
