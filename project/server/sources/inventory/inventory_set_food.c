/*
** inventory_set_food.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:35:29 2014 damien sauvalle
** Last update Sun Jun 29 18:35:50 2014 damien sauvalle
*/

#include	"inventory.h"

void	inventory_set_food(t_inventory *inventory, unsigned int val)
{
  inventory->food = val;
}
