/*
** inventory_set_deraumere.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:34:49 2014 damien sauvalle
** Last update Wed Jul  2 16:10:51 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "assert.h"
#include	"inventory.h"

void	inventory_set_deraumere(t_inventory *inventory, unsigned char val)
{
  assert(inventory != NULL);
  inventory->deraumere = val;
}
