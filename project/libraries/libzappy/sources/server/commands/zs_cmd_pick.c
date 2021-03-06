/*
** zs_cmd_pick.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sat Jul 12 19:27:54 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_pick(t_zs *this, t_zc *zc, const char *cmd)
{
  if (!my_match(cmd, "prend *"))
    return (false);
  zs_handle_cmd_pick(this, zc, cmd + 6);
  return (true);
}
