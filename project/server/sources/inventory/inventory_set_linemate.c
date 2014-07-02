/*
** inventory_set_linemate.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:28:34 2014 damien sauvalle
** Last update Wed Jul  2 16:11:06 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "assert.h"
#include	"inventory.h"

void	inventory_set_linemate(t_inventory *inventory, unsigned char val)
{
  assert(inventory != NULL);
  inventory->linemate = val;
}
