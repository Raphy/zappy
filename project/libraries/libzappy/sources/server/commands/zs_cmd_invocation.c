/*
** zs_cmd_invocation.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sun Jul 13 01:01:03 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_invocation(t_zs *this, t_zc *zc, const char *cmd)
{
  if (strcmp(cmd, "incantation") != 0)
    return (false);
  zs_handle_cmd_invocation(this, zc);
  return (true);
}
