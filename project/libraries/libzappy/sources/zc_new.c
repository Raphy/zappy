/*
** zc_new.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 16:28:37 2014 raphael defreitas
** Last update Thu May 15 10:51:59 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

t_zc		*zc_new(void)
{
  t_zc		*this;

  if ((this = calloc(1, sizeof(t_zc))) == NULL)
    return (NULL);
  if (zc_ctor(this) == RET_FAILURE)
    {
      zc_delete(this);
      return (NULL);
    }
  return (this);
}
