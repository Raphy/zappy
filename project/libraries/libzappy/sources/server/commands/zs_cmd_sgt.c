/*
** zs_cmd_sgt.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Thu Jul 10 02:50:52 2014 raphael defreitas
*/

#include	<stdbool.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_sgt(t_zs *this, t_zc *zc, const char *cmd)
{
  if (!my_match(cmd, "sgt"))
    return (false);
  zs_handle_cmd_sgt(this, zc);
  return (true);
}
