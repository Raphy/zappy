#include          "zappy.h"
#include          "server.h"
#include          "list.h"
#include          "tools_timespec.h"

/*
** set the serveur's timeout 
** t_events should be sort by the closest timeout
*/

void handler_before_select(t_zs *zs, t_server *data)
{
  t_timespec time;
  t_event *event;
  
  if (data == NULL || data->events == NULL
          || (event = list_front(data->events)) == NULL)
  {
    printf("No events! What should we do ?");
    zs_set_timeout(zs, 1, 0);
    return;
  }
  clock_gettime(CLOCK_MONOTONIC, &time);
}
