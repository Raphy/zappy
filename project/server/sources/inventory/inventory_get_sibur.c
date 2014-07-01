/*
** inventory_get_sibur.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:57:47 2014 damien sauvalle
** Last update Sun Jun 29 18:58:00 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "assert.h"
#include	"inventory.h"

unsigned int	inventory_get_sibur(t_inventory *inventory)
{
  assert(inventory != NULL);
  return (inventory->sibur);
}
