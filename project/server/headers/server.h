/*
** server.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jun 27 16:16:21 2014 damien sauvalle
** Last update Fri Jun 27 19:17:54 2014 damien sauvalle
*/

#ifndef		SERVER_H_
# define	SERVER_H_

# include	"list.h"

typedef struct	s_arg
{
  int		port;
  int		x_world;
  int		y_world;
  t_list       	*teams_name;
  int		limit_client;
  int		time;
}		t_arg;

int		get_arg(int, char **, t_arg *);

#endif /* !SERVER_H_*/
