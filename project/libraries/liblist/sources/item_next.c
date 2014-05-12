/*
** item_next.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:22:53 2014 raphael defreitas
** Last update Thu Apr 17 19:23:13 2014 raphael defreitas
*/

#include	"list.h"

t_item		*item_next(t_item *this)
{
  return (this->next);
}
