/*
** inventory_set_linemate.c for zappy in /home/damien/zappy/project/server/sources/inventory
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 18:28:34 2014 damien sauvalle
** Last update Sun Jun 29 18:30:04 2014 damien sauvalle
*/

#include	"inventory.h"

void	inventory_set_linemate(t_inventory *inventory, unsigned int val)
{
  inventory->linemate = val;
}