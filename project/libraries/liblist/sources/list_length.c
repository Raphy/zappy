/*
** list_length.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:50:26 2014 raphael defreitas
** Last update Sun Jun 29 06:26:17 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<sys/types.h>

#include	"list.h"

size_t		list_length(t_list *this)
{
  if (this == NULL)
    return (0);
  return (this->length);
}
