/*
** zc_cmd_seg.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sun Jul 13 05:38:20 2014 raphael defreitas
*/

#include	<stdbool.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zc_cmd_seg(t_zc *this, const char *cmd)
{
  if (!my_match(cmd, "seg *"))
    return (false);
  zc_handle_cmd_seg(this, cmd + 4);
  return (true);
}
