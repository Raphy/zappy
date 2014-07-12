/*
** zs_cmd_look.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sun Jul 13 01:00:33 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_look(t_zs *this, t_zc *zc, const char *cmd)
{
  if (strcmp(cmd, "voir") != 0)
    return (false);
  zs_handle_cmd_look(this, zc);
  return (true);
}
