/*
** iterator_reset.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:37:25 2014 raphael defreitas
** Last update Thu Apr 17 19:38:05 2014 raphael defreitas
*/

#include	"list.h"

void		iterator_reset(t_iterator *this)
{
  this->current = this->list->front;
}
