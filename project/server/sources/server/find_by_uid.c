/*
** find_by_uid.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 15:57:20 2014 damien sauvalle
** Last update Sat Jul 12 16:11:05 2014 damien sauvalle
*/

#include	"player.h"
#include	"zappy.h"

bool find_by_uid(t_player *player, unsigned int *uid)
{
  if (player == NULL || uid == NULL)
    return (false);
  return (zc_get_uid(player->zc) == *uid);
}
