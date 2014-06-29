/*
** list_new.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 20:01:45 2014 raphael defreitas
** Last update Sun Jun 29 06:27:24 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

t_list		*list_new(void (*data_free_fptr)())
{
  t_list	*this;

  if ((this = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if (list_ctor(this, data_free_fptr) == RET_FAILURE)
    {
      list_delete(this);
      return (NULL);
    }
  return (this);
}
