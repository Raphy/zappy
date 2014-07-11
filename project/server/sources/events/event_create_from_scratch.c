#include  "event.h"
#include  "tools_timespec.h"
#include  "list.h"

static int        add_to_server(t_server *server, t_bundle_event *bundle)
{
  t_event         *event;
  t_item          *tmp;
  t_event         *tmp_event;
  t_iterator      it;
  
  if (bundle == NULL || server == NULL || (event = event_new(bundle)) == NULL)
    return (RET_FAILURE);
  iterator_ctor(&it, server->events, IT_ITEM);
  while ((tmp = iterator_current(&it)) != NULL &&
          (tmp_event = item_data(tmp)) != NULL &&
          timespec_compare(&(event->end_time), &(tmp_event->end_time)) <= 0)
    iterator_next(&it);
  if (tmp == NULL)
    list_enqueue(server->events, event);
  else
    list_insert(server->events, tmp, event, 1);
  return (RET_SUCCESS);
}

int               event_create_from_scratch(t_scratch_event *scratch, t_bundle *data)
{
  t_server        *server;
  t_bundle_event  event_bundle;
  
  if (data == NULL || (server = data->server) == NULL)
    return (EXIT_FAILURE);
  event_bundle.action = scratch->action;
  event_bundle.cycle = scratch->cycle;
  clock_gettime(CLOCK_MONOTONIC, &event_bundle.end_time);
  timespec_add_double(&(event_bundle.end_time),
          (double)(scratch->cycle / server->arg->time));
  event_bundle.data = data;
  event_bundle.player = data->player;
  return (add_to_server(server, &event_bundle));
}