/*
** server.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:40:36 2014 damien sauvalle
** Last update Thu Jul  3 19:24:16 2014 damien sauvalle
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

/*
  LINEMATE = 80 %
  DERAUMERE = 65 %
  SIBUR = 55 %
  MENDIANE = 45 %
  PHIRAS  = 25
  THYSTANE 5 %
  FOOD = 60 %
*/


void generate_ressource(t_server *, t_arg *);


/*
** Fonction pour acceder au ressource d'une case definie
** Pour les joueurs Finder via Id
*/


#endif /* !SERVER_H_ */
