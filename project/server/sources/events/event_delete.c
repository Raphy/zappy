#include  "event.h"

void      event_delete(t_event *event)
{
  if (event != NULL)
  {
    event_dtor(event);
    free(event);
  }
}