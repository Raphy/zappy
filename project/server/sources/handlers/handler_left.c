/*
** handler_left.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jul 13 01:54:52 2014 damien sauvalle
** Last update Sun Jul 13 01:55:04 2014 damien sauvalle
*/

#include	"zappy.h"
#include	"player.h"
#include	"bundle.h"
#include	"event.h"
#include	"player_action.h"

void          handler_left(__attribute__((unused))t_zs *zs,
        __attribute__((unused))t_zc *zc, void *data)
{
  t_scratch_event bundle;

  if (data == NULL)
    return ;
  bundle.action = &player_action_left;
  bundle.cycle = 7;
  event_create_from_scratch(&bundle, (t_bundle*)data);
}
