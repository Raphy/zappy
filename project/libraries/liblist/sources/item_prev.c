/*
** item_prev.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:23:24 2014 raphael defreitas
** Last update Sun Jun 29 06:32:43 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

t_item		*item_prev(t_item *this)
{
  if (this == NULL)
    return (NULL);
  return (this->prev);
}
