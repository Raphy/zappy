/*
** handler_pick.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jul 13 11:42:41 2014 damien sauvalle
** Last update Sun Jul 13 14:46:28 2014 damien sauvalle
*/

#include	<string.h>

#include	"zappy.h"
#include	"player.h"
#include	"bundle.h"
#include	"event.h"
#include	"player_action.h"

void          handler_pick(t_zs *zs, t_zc *zc, const char *str, void *data)
{
  t_scratch_event bundle;

  if (data == NULL)
    return ;
  bundle.action = &player_action_pick;
  bundle.cycle = 7;
  ((t_bundle*)data)->str = strdup(str);
  event_create_from_scratch(&bundle, (t_bundle*)data);
}
