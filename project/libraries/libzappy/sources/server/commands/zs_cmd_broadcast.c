/*
** zs_cmd_broadcast.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sat Jul 12 19:28:37 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_broadcast(t_zs *this, t_zc *zc, const char *cmd)
{
  if (!my_match(cmd, "broadcast *"))
    return (false);
  zs_handle_cmd_broadcast(this, zc, cmd + 10);
  return (true);
}
