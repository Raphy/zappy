/*
** inventory.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:45:28 2014 damien sauvalle
** Last update Sun Jun 29 19:36:28 2014 damien sauvalle
*/

#ifndef		INVENTORY_H_
# define	INVENTORY_H_
/*
typedef enum
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTANE,
    FOOD
  }	t_stock;

# define	SIZE_INVENTORY 7
*/

typedef struct	s_inventory
{
  unsigned int	linemate;
  unsigned int	deraumere;
  unsigned int	sibur;
  unsigned int	mendiane;
  unsigned int	phiras;
  unsigned int	thystane;
  unsigned int	food;
}		t_inventory;

/*
** Inventory
*/
int			inventory_ctor(t_inventory *);
void			inventory_dtor(t_inventory *);

void			inventory_set_linemate(t_inventory *, unsigned int);
void			inventory_set_mendiane(t_inventory *, unsigned int);
void			inventory_set_deraumere(t_inventory *, unsigned int);
void			inventory_set_sibur(t_inventory *, unsigned int);
void			inventory_set_phiras(t_inventory *, unsigned int);
void			inventory_set_thystane(t_inventory *, unsigned int);
void			inventory_set_food(t_inventory *, unsigned int);

unsigned int		inventory_get_linemate(t_inventory *);
unsigned int		inventory_get_mendiane(t_inventory *);
unsigned int		inventory_get_deraumere(t_inventory *);
unsigned int		inventory_get_sibur(t_inventory *);
unsigned int		inventory_get_phiras(t_inventory *);
unsigned int		inventory_get_thystane(t_inventory *);
unsigned int		inventory_get_food(t_inventory *);

#endif /* !INVENTORY_H_ */
