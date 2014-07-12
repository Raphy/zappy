/*
** zc_cmd_eht.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sat Jul 12 13:25:13 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

bool		zc_cmd_eht(t_zc *this, const char *cmd)
{
  unsigned int	eid;

  if (!my_match(cmd, "eht *"))
    return (false);
  if (!my_str_is_numeric(cmd + 4))
    return (true);
  eid = strtoul(cmd + 4, NULL, 0);
  zc_handle_cmd_eht(this, eid);
  return (true);
}
