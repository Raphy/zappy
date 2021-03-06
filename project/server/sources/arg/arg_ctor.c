/*
** arg_ctor.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 00:05:47 2014 damien sauvalle
** Last update Sun Jun 29 17:19:33 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"arg.h"
#include	"zappy.h"

int	arg_ctor(t_arg *arg)
{
  if (arg == NULL)
    return (RET_FAILURE);
  if ((arg->team_names = list_new(NULL)) == NULL)
    return (RET_FAILURE);
  arg->port = -1;
  arg->x_world = -1;
  arg->y_world = -1;
  arg->limit_client = -1;
  arg->time = -1;
  return (RET_SUCCESS);
}
