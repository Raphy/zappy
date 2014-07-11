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

  printf("before select\n");
  server = (t_server*)data;
  clock_gettime(CLOCK_MONOTONIC, &time);
  if (data == NULL || server->events == NULL
          || (event = list_front(server->events)) == NULL)
  {
    printf("bloquant\n");
    zs_disable_timeout(zs);
    return;
  }
  timespec_sub(&(event->end_time), &time);
  printf("time %d.%d\n", time.tv_sec, time.tv_nsec);
  if (time.tv_sec < 0 || time.tv_nsec < 0)
    zs_set_timeout(zs, 0, 0);
  else
    zs_set_timeout(zs, time.tv_sec, time.tv_nsec);
}
