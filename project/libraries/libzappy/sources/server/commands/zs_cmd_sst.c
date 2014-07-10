/*
** zs_cmd_sst.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Thu Jul 10 02:50:18 2014 raphael defreitas
*/

#include	<stdbool.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_sst(t_zs *this, t_zc *zc, const char *cmd)
{
  unsigned int	time;

  if (!my_match(cmd, "sst *"))
    return (false);
  if (!my_str_is_numeric(cmd + 4))
    {
      // ToDo SBP
      return (true);
    }
  time = strtoul(cmd + 4, NULL, 0);
  zs_handle_cmd_sst(this, zc, time);
  return (true);
}
