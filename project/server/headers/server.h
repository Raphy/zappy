/*
** server.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul  3 23:21:49 2014 damien sauvalle
** Last update Fri Jul  4 15:02:48 2014 damien sauvalle
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "inventory.h"
# include "list.h"
# include "arg.h"

typedef struct	s_server
{
  t_inventory   **map;
  t_list        *players;
}		t_server;

int	server_ctor(t_server *, t_arg *);
void	server_dtor(t_server *, t_arg *);

void	dump_map(t_server *, t_arg *);

typedef void (*fill)(t_inventory **, t_arg *, int);

typedef struct s_fill_map
{
  fill		fill;
}		t_fill_map;

/*
  LINEMATE = 80 %
  DERAUMERE = 65 %
  SIBUR = 55 %
  MENDIANE = 45 %
  PHIRAS  = 25
  THYSTANE 5 %
  FOOD = 60 %
*/


void	generate_ressource(t_server *, t_arg *);
void	fill_linemate(t_inventory **, t_arg *, int);
void	fill_deraumere(t_inventory **, t_arg *, int);
void	fill_sibur(t_inventory **, t_arg *, int);
void	fill_mendiane(t_inventory **, t_arg *, int);
void	fill_phiras(t_inventory **, t_arg *, int);
void	fill_thystane(t_inventory **, t_arg *, int);
void	fill_food(t_inventory **, t_arg *, int);

/*
** Fonction pour acceder au ressource d'une case definie
** Pour les joueurs Finder via Id
*/


#endif /* !SERVER_H_ */
