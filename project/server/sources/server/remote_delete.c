/*
** remote_delete.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 17:10:53 2014 damien sauvalle
** Last update Thu Jul 10 17:34:29 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"my.h"
#include	"server.h"

void	remote_delete(t_remote *remote)
{
  remote_dtor(remote);
  free(remote);
}
