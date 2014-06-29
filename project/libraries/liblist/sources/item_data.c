/*
** item_data.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:19:55 2014 raphael defreitas
** Last update Sun Jun 29 06:32:27 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*item_data(t_item *this)
{
  if (this == NULL)
    return (NULL);
  return (this->data);
}
