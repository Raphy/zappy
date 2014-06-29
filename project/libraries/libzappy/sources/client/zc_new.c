/*
** zc_new.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:48:15 2014 raphael defreitas
** Last update Thu Jun 26 13:13:49 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

t_zc		*zc_new(void)
{
  t_zc		*this;

  if ((this = malloc(sizeof(t_zc))) == NULL)
    return (NULL);
  if (zc_ctor(this) == RET_FAILURE)
    {
      zc_delete(this);
      return (NULL);
    }
  return (this);
}
