/*
** arg.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jun 27 16:16:21 2014 damien sauvalle
** Last update Sun Jul 13 11:01:28 2014 damien sauvalle
*/

#ifndef		ARG_H_
# define	ARG_H_

# include	"list.h"

typedef struct	s_arg
{
  int		port;
  unsigned int	x_world;
  unsigned int	y_world;
  t_list	*team_names;
  unsigned int	limit_client;
  unsigned int	time;
}		t_arg;

typedef int	(*function)(char **, t_arg *, int);

typedef struct	s_parse_map
{
  char		index;
  function	function;
}               t_parser_map;

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
int		arg_parse_port(char **, t_arg *, int);
int		arg_parse_x_world(char **, t_arg *, int);
int		arg_parse_y_world(char **, t_arg *, int);
int		arg_parse_team_names(char **, t_arg *, int);
int		arg_parse_limit_client(char **, t_arg *, int);
int		arg_parse_time(char **, t_arg *, int);

#endif /* !ARG_H_ */
