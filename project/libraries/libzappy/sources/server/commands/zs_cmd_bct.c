/*
** zs_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sat Jul 12 23:19:16 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static bool	parse(const char *cmd, t_position *position)
{
  char		*x;
  char		*y;

  if ((x = strdup(cmd + 4)) == NULL)
    return (false);
  y = strchr(x, ' ');
  x[y - x] = 0;
  y++;
  if (!my_str_is_numeric(x) || !my_str_is_numeric(y))
    {
      free(x);
      return (false);
    }
  position->x = strtoul(x, NULL, 0);
  position->y = strtoul(y, NULL, 0);
  free(x);
  return (true);
}

bool		zs_cmd_bct(t_zs *this, t_zc *zc, const char *cmd)
{
  t_position	position;

  if (strncmp(cmd, "bct", 3) != 0)
    return (false);
  if (!my_match(cmd, "bct * *") ||
      !parse(cmd, &position))
    {
      zs_send_cmd_sbp(this, zc);
      return (true);
    }
  zs_handle_cmd_bct(this, zc, &position);
  return (true);
}
