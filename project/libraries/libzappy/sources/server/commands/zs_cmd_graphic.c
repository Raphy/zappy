/*
** zs_cmd_graphic.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 05:53:47 2014 raphael defreitas
** Last update Sat Jul 12 18:15:22 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_graphic(t_zs *this, t_zc *zc, const char *cmd)
{
  if (strcmp(cmd, "GRAPHIC") != 0)
    return (false);
  zs_handle_cmd_graphic(this, zc);
  return (true);
}
