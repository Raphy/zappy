/*
** zs_cmd_ppo.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Thu Jul 10 01:48:28 2014 raphael defreitas
*/

#include	<stdbool.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_ppo(t_zs *this, t_zc *zc, const char *cmd)
{
  unsigned int	uid;

  if (!my_match(cmd, "ppo *"))
    return (false);
  if (!my_str_is_numeric(cmd + 4))
    {
      // ToDo SBP
      return (true);
    }
  uid = strtoul(cmd + 4, NULL, 0);
  zs_handle_cmd_ppo(this, zc, uid);
  return (true);
}
