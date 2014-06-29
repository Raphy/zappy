/*
** iterator_next.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:26:00 2014 raphael defreitas
** Last update Sun Jun 29 06:28:39 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		iterator_next(t_iterator *this)
{
  if (this == NULL)
    return ;
  if (this->current)
    this->current = this->current->next;
}
