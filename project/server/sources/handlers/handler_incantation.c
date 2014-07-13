#include "zappy.h"
#include  "player.h"
#include "bundle.h"
#include "event.h"
#include	"player_action.h"
#include <assert.h>
#include <string.h>

static const struct s_elevation_condition g_conditions[7] = \
{
    {
        1, { 0, 1, 0, 0, 0, 0, 0 }
    },
    {
        2, { 0, 1, 1, 1, 0, 0, 0 }
    },
    {
        2, { 0, 2, 0, 1, 0, 2, 0 }
    },
    {
        4, { 0, 1, 1, 2, 0, 1, 0 }
    },
    {
        4, { 0, 1, 2, 1, 3, 0, 0 }
    },
    {
        6, { 0, 1, 2, 3, 0, 1, 0 }
    },
    {
        6, { 0, 2, 2, 2, 2, 2, 1 }
    }
};

int     verify_elevation_condition(const t_player *player, const t_case *current)
{
    assert(sizeof(t_items) - sizeof(unsigned char) > 0);
    if (player->level > 7 || current->players.length != g_conditions[player->level - 1].player_required)
        return RET_FAILURE;
    if (memcmp(&(current->inventory) + sizeof(unsigned char), &(g_conditions->items) + sizeof(unsigned char), sizeof(t_items) - sizeof(unsigned char)))
        return RET_FAILURE;
    return RET_SUCCESS;
}

void          handler_incantation(t_zs *zs, t_zc *zc, void *data)
{
  t_scratch_event bundle;
  t_bundle *datas;
  t_case *current;
  
  if (data == NULL)
    return;
  datas = (t_bundle *)data;
  current = &(datas->server->map[datas->player->y][datas->player->x]);
  if (verify_elevation_condition(datas->player, current) == RET_FAILURE)
  {
      zs_send_ko(zs, zc);
      return;
  }
  bundle.action = &player_action_incantation;
  bundle.cycle = 300;
  event_create_from_scratch(&bundle, (t_bundle*)data);
}
