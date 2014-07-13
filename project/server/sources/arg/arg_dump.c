/*
** arg_dump.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/arg
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Sun Jun 29 17:39:18 2014 raphael defreitas
** Last update Sun Jul 13 11:21:37 2014 damien sauvalle
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"arg.h"
#include	"list.h"

void		arg_dump(t_arg *this)
{
  t_iterator	it;
  char		*team_name;

  if (this == NULL)
    return ;
  printf("Running on port:  %d\n", arg_get_port(this));
  printf("World size:       %d / %d\n", arg_get_world_width(this),
	 arg_get_world_height(this));
  printf("Clients per team: %d\n", arg_get_clients_per_team(this));
  printf("Time:             %d\n", arg_get_time(this));
  printf("Team names:       ");
  iterator_ctor(&it, this->team_names, IT_DATA);
  while ((team_name = iterator_current(&it)))
    {
      iterator_next(&it);
      printf("« %s »%s", team_name, iterator_current(&it) ? ", " : "");
    }
  printf("\n\n");
  iterator_dtor(&it);
}
