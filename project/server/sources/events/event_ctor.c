#include  "event.h"

int   event_ctor(t_event *event, t_bundle_event *bundle)
{
  if (event == NULL)
    return (RET_FAILURE);
  event->action = bundle->action;
  event->data = bundle->data;
  event->end_time.tv_sec = bundle->end_time.tv_sec;
  event->end_time.tv_nsec = bundle->end_time.tv_nsec;
  event->player = bundle->player;
  event->cycle = bundle->cycle;
  return (RET_SUCCESS);
}