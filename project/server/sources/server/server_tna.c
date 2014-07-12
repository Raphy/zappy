/*
** server_tna.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 00:17:32 2014 damien sauvalle
** Last update Sat Jul 12 01:52:55 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"

void	server_tna(t_server *server, t_zc *zc, t_zs *zs)
{
  t_iterator it;
  char *name;

  iterator_ctor(&it, server->arg->team_names, IT_DATA);
  while ((name = iterator_current(&it)))
    {
      zs_send_cmd_tna(zs, zc, name);
      iterator_next(&it);
    }
}
