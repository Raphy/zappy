/*
** item_new.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:57:52 2014 raphael defreitas
** Last update Sun Jun 29 06:29:58 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

t_item		*item_new(void *data, void (*data_free_fptr)())
{
  t_item	*this;

  if ((this = malloc(sizeof(t_item))) == NULL)
    return (NULL);
  if (item_ctor(this, data, data_free_fptr) == RET_FAILURE)
    {
      item_delete(this);
      return (NULL);
    }
  return (this);
}
