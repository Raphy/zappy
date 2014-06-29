/*
** stock.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 15:45:28 2014 damien sauvalle
** Last update Sun Jun 29 15:49:57 2014 damien sauvalle
*/

#ifndef		STOCK_H_
# define	STOCK_H_

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

# define	SIZE_STOCK 7

/*
** Stock
*/
int			*stock_ctor();
void			stock_dtor(unsigned int *);

void			stock_set_linemate(unsigned int *, unsigned int);
void			stock_set_deraumere(unsigned int *, unsigned int);
void			stock_set_sibur(unsigned int *, unsigned int);
void			stock_set_phiras(unsigned int *, unsigned int);
void			stock_set_thystane(unsigned int *, unsigned int);
void			stock_set_food(unsigned int *, unsigned int);

unsigned int		stock_get_linemate(unsigned int *);
unsigned int		stock_get_deraumere(unsigned int *);
unsigned int		stock_get_sibur(unsigned int *);
unsigned int		stock_get_phiras(unsigned int *);
unsigned int		stock_get_thystane(unsigned int *);
unsigned int		stock_get_food(unsigned int *);

#endif /* !STOCK_H_ */
