/*
** arg_get_team_names.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/arg
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 17:27:28 2014 raphael defreitas
** Last update Sun Jun 29 17:29:11 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"arg.h"
#include	"list.h"

t_list		*arg_get_team_names(t_arg *this)
{
  if (this == NULL)
    return (NULL);
  return (this->team_names);
}
