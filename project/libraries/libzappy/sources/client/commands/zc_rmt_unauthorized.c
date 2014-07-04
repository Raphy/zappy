/*
** zc_rmt_unauthorized.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Fri Jul  4 00:12:20 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zc_rmt_unauthorized(t_zc *this, const char *cmd)
{
  if (strcmp(cmd, "RMT UNAUTHORIZED") != 0)
    return (false);
  zc_handle_rmt_unauthorized(this);
  return (true);
}
