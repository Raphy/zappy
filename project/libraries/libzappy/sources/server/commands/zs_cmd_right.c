/*
** zs_cmd_right.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sat Jul  5 15:52:32 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_right(t_zs *this, t_zc *zc, const char *cmd)
{
  if (strcmp(cmd, "droite") != 0)
    return (false);
  zs_handle_cmd_right(this, zc);
  return (true);
}
