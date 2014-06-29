/*
** iterator_reset.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:37:25 2014 raphael defreitas
** Last update Sun Jun 29 06:27:41 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		iterator_reset(t_iterator *this)
{
  if (this == NULL)
    return ;
  this->current = this->list->front;
}
