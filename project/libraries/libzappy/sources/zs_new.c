/*
** zs_new.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 15:31:09 2014 raphael defreitas
** Last update Mon May 12 15:59:04 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

t_zs		*zs_new(int port)
{
  t_zs		*this;

  if ((this = calloc(1, sizeof(t_zs))) == NULL)
    return (NULL);
  if (zs_ctor(this, port) == RET_FAILURE)
    {
      zs_delete(this);
      return (NULL);
    }
  return (this);
}
