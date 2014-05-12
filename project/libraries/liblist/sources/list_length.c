/*
** list_length.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:50:26 2014 raphael defreitas
** Last update Thu Apr 17 19:50:53 2014 raphael defreitas
*/

#include	<sys/types.h>

#include	"list.h"

size_t		list_length(t_list *this)
{
  return (this->length);
}
