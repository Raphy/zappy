/*
** inventory.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:45:28 2014 damien sauvalle
** Last update Sat Jul 12 17:47:51 2014 damien sauvalle
*/

#ifndef		INVENTORY_H_
# define	INVENTORY_H_

# include	"zappy.h"

typedef enum
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTANE,
    FOOD
  }	t_type_inventory;

# define	SIZE_INVENTORY 7

int			inventory_ctor(t_items *);
void			inventory_dtor(t_items *);

#endif /* !INVENTORY_H_ */
