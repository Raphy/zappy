/*
** list_back.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:49:54 2014 raphael defreitas
** Last update Thu Apr 17 19:54:28 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		*list_back(t_list *this)
{
  if (this->back)
    return (item_data(this->back));
  return (NULL);
}
