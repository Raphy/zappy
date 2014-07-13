/*
** zc_cmd_smg.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sat Jul 12 18:19:40 2014 raphael defreitas
*/

#include	<stdbool.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zc_cmd_smg(t_zc *this, const char *cmd)
{
  if (!my_match(cmd, "smg *"))
    return (false);
  zc_handle_cmd_smg(this, cmd + 4);
  return (true);
}
