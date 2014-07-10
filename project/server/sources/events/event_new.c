#include  "event.h"

t_event *event_new(t_bundle_event *bundle)
{
  t_event *result;
  
  if ((result = malloc(sizeof(*result))) == NULL)
    return (NULL);
  if (bundle == NULL || event_ctor(result, bundle) != RET_SUCCESS)
  {
    event_delete(result);
    return (NULL);
  }
  return (result);
}