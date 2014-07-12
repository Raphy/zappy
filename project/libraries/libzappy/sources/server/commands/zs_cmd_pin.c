/*
** zs_cmd_pin.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sun Jul 13 00:03:24 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_pin(t_zs *this, t_zc *zc, const char *cmd)
{
  unsigned int	uid;

  if (strncmp(cmd, "pin", 3) != 0)
    return (false);
  if (!my_match(cmd, "pin *") ||
      !my_str_is_numeric(cmd + 4))
    {
      zs_send_cmd_sbp(this, zc);
      return (true);
    }
  uid = strtoul(cmd + 4, NULL, 0);
  zs_handle_cmd_pin(this, zc, uid);
  return (true);
}
