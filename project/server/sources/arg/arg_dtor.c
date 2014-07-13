/*
** arg_dtor.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 00:11:19 2014 damien sauvalle
** Last update Sun Jul 13 11:21:21 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"arg.h"
#include	"list.h"

void	arg_dtor(t_arg *arg)
{
  if (arg == NULL)
    return ;
  list_delete(arg->team_names);
}
