/*
** zc_cmd_tna.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Wed Jul  9 18:36:07 2014 raphael defreitas
*/

#include	<stdbool.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zc_cmd_tna(t_zc *this, const char *cmd)
{
  if (!my_match(cmd, "tna *"))
    return (false);
  zc_handle_cmd_tna(this, cmd + 4);
  return (true);
}
