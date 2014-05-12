/*
** item_new.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:57:52 2014 raphael defreitas
** Last update Thu Apr 17 20:00:04 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

t_item		*item_new(void *data, void (*data_free_fptr)())
{
  t_item	*this;

  if ((this = malloc(sizeof(t_item))) == NULL)
    return (NULL);
  item_ctor(this, data, data_free_fptr);
  return (this);
}
