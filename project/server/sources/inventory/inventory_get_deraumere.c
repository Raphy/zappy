/*
** inventory_get_deraumere.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:53:28 2014 damien sauvalle
** Last update Sun Jun 29 18:54:51 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "assert.h"
#include	"inventory.h"

unsigned int	inventory_get_deraumere(t_inventory *inventory)
{
  assert(inventory != NULL);
  return (inventory->deraumere);
}
