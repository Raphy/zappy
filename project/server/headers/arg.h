/*
** arg.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jun 27 16:16:21 2014 damien sauvalle
** Last update Sun Jun 29 17:39:04 2014 raphael defreitas
*/

#ifndef		ARG_H_
# define	ARG_H_

# include	"list.h"

typedef void (*function)(void);

typedef struct
{
  char          index;
  function      function;
}               t_parser_map;

typedef struct
{
  int		port;
  int		x_world;
  int		y_world;
  t_list       	*team_names;
  int		limit_client;
  int		time;
}		t_arg;

int		arg_ctor(t_arg *);
void		arg_dtor(t_arg *);

int		arg_get_port(t_arg *);
int		arg_get_world_width(t_arg *);
int		arg_get_world_height(t_arg *);
t_list		*arg_get_team_names(t_arg *);
int		arg_get_clients_per_team(t_arg *);
int		arg_get_time(t_arg *);

int		arg_parse(t_arg *, int, char **);
void		arg_dump(t_arg *);

int		arg_parse_port(char *, t_arg *);
int		arg_parse_x_world(char *, t_arg *);
int		arg_parse_y_world(char *, t_arg *);
int		arg_parse_team_names(int, char **, t_arg *, int);
int		arg_parse_limit_client(char *, t_arg *);
int		arg_parse_time(char *, t_arg *);

#endif /* !ARG_H_*/
