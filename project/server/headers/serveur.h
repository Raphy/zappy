/*
** serveur.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:40:36 2014 damien sauvalle
** Last update Wed Jul  2 21:27:52 2014 damien sauvalle
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

# include "inventory.h"
# include "list.h"
# include "arg.h"

typedef struct	s_serveur
{
  t_inventory   **map;
  t_list        *players;
}		t_serveur;

int	serveur_ctor(t_serveur *, t_arg *);
void	serveur_dtor(t_serveur *, t_arg *);


/*
** Fonction pour acceder au ressource d'une case definie
** Pour les joueurs Finder via Id
*/


#endif /* !SERVEUR_H_ */
