/*
** inventory_set_mendiane.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:36:18 2014 damien sauvalle
** Last update Sun Jun 29 18:36:35 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "assert.h"
#include	"inventory.h"

void	inventory_set_mendiane(t_inventory *inventory, unsigned int val)
{
  assert(inventory != NULL);
  inventory->mendiane = val;
}
