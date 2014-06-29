/*
** arg_get_world_width.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/arg
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 17:25:12 2014 raphael defreitas
** Last update Sun Jun 29 17:27:15 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"arg.h"
#include	"my.h"

int		arg_get_world_width(t_arg *this)
{
  if (this == NULL)
    return (RET_ERROR);
  return (this->x_world);
}
