/*
** inventory_set_sibur.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:37:43 2014 damien sauvalle
** Last update Sun Jun 29 18:37:53 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "assert.h"
#include	"inventory.h"

void	inventory_set_sibur(t_inventory *inventory, unsigned char val)
{
  assert(inventory != NULL);
  inventory->sibur = val;
}
