#include "zappy.h"
#include  "player.h"
#include "bundle.h"
#include "event.h"
#include	"player_action.h"

void          handler_slot_number(__attribute__((unused))t_zs *zs,
        __attribute__((unused))t_zc *zc, void *data)
{
  t_scratch_event bundle;

  if (data == NULL)
    return ;
  bundle.action = &player_action_slot_number;
  bundle.cycle = 0;
  event_create_from_scratch(&bundle, (t_bundle*)data);
}
