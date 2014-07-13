#include "zappy.h"
#include  "player.h"
#include "bundle.h"
#include "event.h"
#include	"player_action.h"
#include  <string.h>

void          handler_broadcast(__attribute__((unused))t_zs *zs,
        __attribute__((unused))t_zc *zc, const char *str, void *data)
{
  t_scratch_event bundle;

  if (data == NULL)
    return ;
  bundle.action = &player_action_broacast;
  bundle.cycle = 7;
  ((t_bundle*)data)->str = strdup(str);
  event_create_from_scratch(&bundle, (t_bundle*)data);
}
