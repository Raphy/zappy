/*
** graphic_ctor.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 16:51:09 2014 damien sauvalle
** Last update Thu Jul 10 17:10:04 2014 damien sauvalle
*/

#include	"server.h"
#include	"my.h"


int	graphic_ctor(t_graphic *graphic, t_zc *zc)
{
  graphic->zc = zc;
  return (RET_SUCCESS);
}
