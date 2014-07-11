#include "zappy.h"
#include  "player.h"
#include "bundle.h"
#include "event.h"

void          handler_left(t_zs *zs, t_zc *zc, void *data)
{
  t_scratch_event bundle;
  
  if (data == NULL)
    return ;
  (void) zs;
  (void) zc;
  bundle.action = &player_action_left;
  bundle.cycle = 7;
  event_create_from_scratch(&bundle, (t_bundle*)data);
}