/*
** zs_cmd_remote.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 05:53:47 2014 raphael defreitas
** Last update Sun Jun 29 10:35:38 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_remote(t_zs *this, t_zc *zc, const char *cmd)
{
  if (strcmp(cmd, "REMOTE") != 0)
    return (false);
  zs_handle_cmd_remote(this, zc);
  return (true);
}
