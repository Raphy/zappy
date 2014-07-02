/*
** serveur.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:40:36 2014 damien sauvalle
** Last update Sun Jun 29 15:54:30 2014 damien sauvalle
*/

#ifndef SERVEUR_H_
# define SERVEUR_H_

# include "inventory.h"
# include "list.h"

typedef struct
{
  t_inventory   **map;
  t_list        **players;
}         t_serveur;

#endif /* !SERVEUR_H_ */
