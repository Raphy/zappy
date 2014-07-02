/*
** inventory_get_linemate.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:41:06 2014 damien sauvalle
** Last update Sun Jun 29 18:56:13 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "assert.h"
#include	"inventory.h"

unsigned char	inventory_get_linemate(t_inventory *inventory)
{
  assert(inventory != NULL);
  return (inventory->linemate);
}
