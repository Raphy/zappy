/*
** zs_cmd_team_name.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 05:53:47 2014 raphael defreitas
** Last update Sat Jul 12 14:04:51 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

static bool	finder(const char *data, const char *searched)
{
  if (data == NULL || searched == NULL)
    return (false);
  return (strcmp(data, searched) == 0 ? true : false);
}

bool		zs_cmd_team_name(t_zs *this, t_zc *zc, const char *cmd)
{
  char		*team_name;

  if ((team_name = list_find(this->team_names, &finder, cmd, IT_DATA)) == NULL)
    return (false);
  zs_handle_cmd_team_name(this, zc, team_name);
  return (true);
}
