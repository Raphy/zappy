/*
** zeh_new.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 14:22:09 2014 raphael defreitas
** Last update Mon May 12 14:41:36 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

t_zeh		*zeh_new(t_zet type, int (*handler)(), void *data)
{
  t_zeh		*this;

  if ((this = calloc(1, sizeof(t_zeh))) == NULL)
    return (NULL);
  if (zeh_ctor(this, type, handler, data) == RET_FAILURE)
    {
      zeh_delete(this);
      return (NULL);
    }
  return (this);
}
