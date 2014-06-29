/*
** inventory.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:45:28 2014 damien sauvalle
** Last update Sun Jun 29 18:01:39 2014 damien sauvalle
*/

#ifndef		INVENTORY_H_
# define	INVENTORY_H_

typedef enum
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTANE,
    FOOD
  }	t_inventory;

# define	SIZE_INVENTORY 7

/*
** Inventory
*/
int			*inventory_ctor();
void			inventory_dtor(unsigned int *);

void			inventory_set_linemate(unsigned int *, unsigned int);
void			inventory_set_deraumere(unsigned int *, unsigned int);
void			inventory_set_sibur(unsigned int *, unsigned int);
void			inventory_set_phiras(unsigned int *, unsigned int);
void			inventory_set_thystane(unsigned int *, unsigned int);
void			inventory_set_food(unsigned int *, unsigned int);

unsigned int		inventory_get_linemate(unsigned int *);
unsigned int		inventory_get_deraumere(unsigned int *);
unsigned int		inventory_get_sibur(unsigned int *);
unsigned int		inventory_get_phiras(unsigned int *);
unsigned int		inventory_get_thystane(unsigned int *);
unsigned int		inventory_get_food(unsigned int *);

#endif /* !INVENTORY_H_ */
