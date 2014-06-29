/*
** item_next.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:22:53 2014 raphael defreitas
** Last update Sun Jun 29 06:25:59 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

t_item		*item_next(t_item *this)
{
  if (this == NULL)
    return (NULL);
  return (this->next);
}
