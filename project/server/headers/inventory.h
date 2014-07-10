/*
** inventory.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:45:28 2014 damien sauvalle
** Last update Thu Jul 10 19:56:44 2014 damien sauvalle
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


/*
** Inventory
*/
int			inventory_ctor(t_items *);
void			inventory_dtor(t_items *);

/*

void			inventory_set_linemate(t_inventory *, unsigned char);
void			inventory_set_mendiane(t_inventory *, unsigned char);
void			inventory_set_deraumere(t_inventory *, unsigned char);
void			inventory_set_sibur(t_inventory *, unsigned char);
void			inventory_set_phiras(t_inventory *, unsigned char);
void			inventory_set_thystane(t_inventory *, unsigned char);
void			inventory_set_food(t_inventory *, unsigned char);


unsigned char		inventory_get_linemate(t_inventory *);
unsigned char		inventory_get_mendiane(t_inventory *);
unsigned char		inventory_get_deraumere(t_inventory *);
unsigned char		inventory_get_sibur(t_inventory *);
unsigned char		inventory_get_phiras(t_inventory *);
unsigned char		inventory_get_thystane(t_inventory *);
unsigned char		inventory_get_food(t_inventory *);
*/

#endif /* !INVENTORY_H_ */
