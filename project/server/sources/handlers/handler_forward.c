#include "zappy.h"
#include  "player.h"
#include "bundle.h"
#include "event.h"
#include	"player_action.h"

void          handler_forward(__attribute__((unused))t_zs *zs,
        __attribute__((unused))t_zc *zc, void *data)
{
  t_scratch_event bundle;

  if (data == NULL)
    return ;
  bundle.action = &player_action_goahead;
  bundle.cycle = 7;
  event_create_from_scratch(&bundle, (t_bundle*)data);
}
