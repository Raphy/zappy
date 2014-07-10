#include  "server.h"
#include  "tools_timespec.h"

void	handler_after_select(t_zs *zs, void *data)
{
  t_server *server;
  t_iterator it;
  t_event *event;
  t_bundle bundle;
  t_timespec time;
  
  if ((server = (t_server*) data) == NULL)
    return;
  if ((iterator_ctor(&it, server->events, IT_DATA)))
    return;
  clock_gettime(CLOCK_MONOTONIC, &time);
  while ((event = iterator_current(&it)) != NULL
          && timespec_compare(&time, &(event->end_time)) >= 0)
  {
    printf("Event cycle ended");
    if ((bundle.player = event->player) != NULL
            && (bundle.server = server) != NULL)
      event->action(event->player->zc, &bundle);
    iterator_next(&it);
  }
}