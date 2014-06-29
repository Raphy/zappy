/*
** arg_dtor.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 00:11:19 2014 damien sauvalle
** Last update Sun Jun 29 02:14:39 2014 damien sauvalle
*/

#include	"list.h"
#include	"server.h"

void	arg_dtor(t_arg *arg)
{
  list_delete(arg->team_names);
}
