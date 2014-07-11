#include          "zappy.h"
#include          "server.h"
#include          "list.h"
#include          "tools_timespec.h"

/*
** set the serveur's timeout
** t_events should be sort by the closest timeout
*/

void handler_before_select(t_zs *zs, void *data)
{
  t_server *server;
  t_timespec time;
  t_event *event;

  server = (t_server*)data;
  clock_gettime(CLOCK_MONOTONIC, &time);
  printf("sec: %d, nano: %d\n", time.tv_sec, time.tv_nsec);
  if (data == NULL || server->events == NULL
          || (event = list_front(server->events)) == NULL)
  {
    zs_disable_timeout(zs);
    return;
  }
  zs_set_timeout(zs, event->end_time.tv_sec, event->end_time.tv_nsec);
}
