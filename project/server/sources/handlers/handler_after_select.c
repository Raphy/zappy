/*
** handler_after_select.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 01:34:43 2014 damien sauvalle
** Last update Sat Jul 12 01:35:50 2014 damien sauvalle
*/

#include	"bundle.h"
#include	"event.h"
#include  "server.h"
#include  "tools_timespec.h"

void	handler_after_select(t_zs *zs, void *data)
{
  t_server *server;
  t_iterator it;
  t_item    *item;
  t_event *event;
  t_bundle bundle;
  t_timespec time;

  printf("After select\n");
  if ((server = (t_server*) data) == NULL)
    return;
  if ((iterator_ctor(&it, server->events, IT_ITEM)))
    return;
  clock_gettime(CLOCK_MONOTONIC, &time);
  while ((item = iterator_current(&it)) != NULL
          && (event = item_data(item)) != NULL
          && timespec_compare(&time, &(event->end_time)) >= 0)
  {
    printf("Event cycle ended\n");
    if ((bundle.player = event->player) != NULL
            && (bundle.server = server) != NULL)
      event->action(event->player->zc, &bundle);
    list_unlink(server->events, item);
    event_delete(event);
    iterator_next(&it);
  }
}
