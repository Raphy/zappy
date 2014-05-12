/*
** iterator_prev.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:36:28 2014 raphael defreitas
** Last update Thu Apr 17 19:36:59 2014 raphael defreitas
*/

#include	"list.h"

void		iterator_prev(t_iterator *this)
{
  if (this->current)
    this->current = this->current->prev;
}
