/*
** zc_cmd_sbp.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sat Jul 12 17:51:55 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zc_cmd_sbp(t_zc *this, const char *cmd)
{
  if (strcmp(cmd, "sbp") != 0)
    return (false);
  zc_handle_cmd_sbp(this);
  return (true);
}
