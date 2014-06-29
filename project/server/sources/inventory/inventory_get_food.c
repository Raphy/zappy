/*
** inventory_get_food.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:55:18 2014 damien sauvalle
** Last update Sun Jun 29 18:55:49 2014 damien sauvalle
*/

#include	"inventory.h"

unsigned int	inventory_get_food(t_inventory *inventory)
{
  return (inventory->food);
}
