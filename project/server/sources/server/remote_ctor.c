/*
** remote_ctor.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 17:31:12 2014 damien sauvalle
** Last update Thu Jul 10 17:40:56 2014 damien sauvalle
*/

#include	"server.h"
#include	"my.h"

int	remote_ctor(t_remote *remote, t_zc *zc)
{
  remote->zc = zc;
  return (RET_SUCCESS);
}
