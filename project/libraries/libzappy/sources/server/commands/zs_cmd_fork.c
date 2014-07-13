/*
** zs_cmd_fork.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sat Jul 12 19:29:45 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_fork(t_zs *this, t_zc *zc, const char *cmd)
{
  if (strcmp(cmd, "fork") != 0)
    return (false);
  zs_handle_cmd_fork(this, zc);
  return (true);
}
