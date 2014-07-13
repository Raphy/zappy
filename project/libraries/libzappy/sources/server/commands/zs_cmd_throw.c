/*
** zs_cmd_throw.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sat Jul 12 19:27:47 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_throw(t_zs *this, t_zc *zc, const char *cmd)
{
  if (!my_match(cmd, "pose *"))
    return (false);
  zs_handle_cmd_throw(this, zc, cmd + 5);
  return (true);
}
