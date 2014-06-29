/*
** iterator_current.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:25:07 2014 raphael defreitas
** Last update Sun Jun 29 06:31:09 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*iterator_current(t_iterator *this)
{
  if (this == NULL)
    return (NULL);
  if (this->current && this->type == IT_ITEM)
    return (this->current);
  if (this->current && this->type == IT_DATA)
    return (item_data(this->current));
  return (NULL);
}
