/*
** handler_before_select.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 01:36:19 2014 damien sauvalle
** Last update Sat Jul 12 01:36:36 2014 damien sauvalle
*/

#include	"event.h"
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
  unsigned int test1;
  unsigned int test2;
  t_timespec time;
  t_event *event;

  printf("before select\n");
  server = (t_server*)data;
  clock_gettime(CLOCK_MONOTONIC_RAW, &time);
  if (data == NULL || server->events == NULL
          || (event = list_front(server->events)) == NULL)
  {
    printf("non bloquant\n");
    zs_set_timeout(zs, 1, 0);
    return;
  }
  time = timespec_create_sub(&(event->end_time), &time);
  printf("my time %d.%d\n", time.tv_sec, time.tv_nsec);
  if (time.tv_sec < 0 || time.tv_nsec < 0)
    zs_set_timeout(zs, 0, 1);
  else
    zs_set_timeout(zs, time.tv_sec, time.tv_nsec / 1000);
  printf("timesaved is: %d.%d\n", zs_get_timeout(zs).tv_sec, zs_get_timeout(zs).tv_usec);
}
