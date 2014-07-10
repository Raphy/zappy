/*
** graphic_delete.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 17:10:53 2014 damien sauvalle
** Last update Thu Jul 10 17:12:33 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"my.h"
#include	"server.h"

void	graphic_delete(t_graphic *graphic)
{
  graphic_dtor(graphic);
  free(graphic);
}
