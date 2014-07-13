/*
** inventory_ctor.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:06:02 2014 damien sauvalle
** Last update Thu Jul 10 19:59:23 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "assert.h"
#include	"my.h"
#include	"inventory.h"

int	inventory_ctor(t_items *inventory)
{
  if (inventory == NULL)
    return (RET_FAILURE);
  inventory->linemate = 0;
  inventory->deraumere = 0;
  inventory->sibur = 0;
  inventory->mendiane = 0;
  inventory->phiras = 0;
  inventory->thystame = 0;
  inventory->food = 10;
  return (RET_SUCCESS);
}
