/*
** server.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul  3 23:21:49 2014 damien sauvalle
** Last update Mon Jul  7 17:09:03 2014 damien sauvalle
*/

#ifndef SERVER_H_
# define SERVER_H_

# include	"inventory.h"
# include	"list.h"
# include	"arg.h"
# include	"case.h"
# include       "event.h"

typedef struct	s_server
{
  t_case	**map;
  t_list        *players;
  t_list        *events;
  t_list	eggs;
}		t_server;

int	server_ctor(t_server *, t_arg *);
void	server_dtor(t_server *, t_arg *);
void	dump_map(t_server *, t_arg *);

typedef void (*fill)(t_case **, t_arg *, int);

typedef struct	s_fill_map
{
  fill		fill;
}		t_fill_map;

void	generate_ressource(t_server *, t_arg *);
void	fill_linemate(t_case **, t_arg *, int);
void	fill_deraumere(t_case **, t_arg *, int);
void	fill_sibur(t_case **, t_arg *, int);
void	fill_mendiane(t_case **, t_arg *, int);
void	fill_phiras(t_case **, t_arg *, int);
void	fill_thystane(t_case **, t_arg *, int);
void	fill_food(t_case **, t_arg *, int);

/*
** Fonction pour acceder au ressource d'une case definie
** Pour les joueurs Finder via Id
*/

#endif /* !SERVER_H_ */
