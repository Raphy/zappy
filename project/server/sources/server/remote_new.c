/*
** remote_new.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 16:51:14 2014 damien sauvalle
** Last update Thu Jul 10 17:32:19 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"
#include	"my.h"

t_remote	*remote_new(t_zc *zc)
{
  t_remote	*new;

  if ((new = malloc(sizeof(t_remote))) == NULL)
    return (NULL);
  if (remote_ctor(new, zc) == RET_FAILURE)
    {
      remote_delete(new);
      return (NULL);
    }
  return (new);
}
