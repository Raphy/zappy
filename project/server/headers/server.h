/*
** server.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jun 27 16:16:21 2014 damien sauvalle
** Last update Sun Jun 29 02:13:29 2014 damien sauvalle
*/

#ifndef		SERVER_H_
# define	SERVER_H_

# include	"list.h"

typedef struct	s_arg
{
  int		port;
  int		x_world;
  int		y_world;
  t_list       	*team_names;
  int		limit_client;
  int		time;
}		t_arg;

int		arg_parse(t_arg *, int, char **);
int		arg_ctor(t_arg *);
void		arg_dtor(t_arg *);
int		arg_parse_port(char *, t_arg *);
int		arg_parse_x_world(char *, t_arg *);
int		arg_parse_y_world(char *, t_arg *);
int		arg_parse_team_names(int, char **, t_arg *, int);
int		arg_parse_limit_client(char *, t_arg *);
int		arg_parse_time(char *, t_arg *);
int		check_int(char *);

#endif /* !SERVER_H_*/
