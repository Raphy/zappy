/*
** server_sst.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 16:02:38 2014 damien sauvalle
** Last update Sat Jul 12 16:20:18 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"
#include	"player.h"

void		server_sst(t_zs *zs, t_zc *zc, unsigned int nbr, void *d)
{
  ((t_server *)d)->arg->time = nbr;
  server_sgt(zs, zc, d);
}
