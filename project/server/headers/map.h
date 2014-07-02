/*
** map.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:40:36 2014 damien sauvalle
** Last update Sun Jun 29 15:54:30 2014 damien sauvalle
*/

#ifndef MAP_H_
# define MAP_H_

# include "inventory.h"
# include "list.h"


typedef struct
{
  t_inventory   **map;
  t_list        **players;
}         t_map;



#endif /* !MAP_H_ */
