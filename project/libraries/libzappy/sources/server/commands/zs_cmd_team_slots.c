/*
** zs_cmd_team_slots.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sun Jul 13 01:02:22 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_team_slots(t_zs *this, t_zc *zc, const char *cmd)
{
  unsigned int	team_slots;

  if (!my_str_is_numeric(cmd))
    return (false);
  team_slots = strtoul(cmd, NULL, 0);
  zs_handle_cmd_team_slots(this, zc, team_slots);
  return (true);
}
