/*
** zs_new.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:25:43 2014 raphael defreitas
** Last update Thu Jun 26 11:28:22 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

t_zs		*zs_new(int port)
{
  t_zs		*this;

  if ((this = malloc(sizeof(t_zs))) == NULL)
    return (NULL);
  if (zs_ctor(this, port) == RET_FAILURE)
    {
      zs_delete(this);
      return (NULL);
    }
  return (this);
}
