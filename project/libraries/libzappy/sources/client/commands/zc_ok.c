/*
** zc_ok.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sun Jul  6 18:56:30 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zc_ok(t_zc *this, const char *cmd)
{
  if (strcmp(cmd, "ok") != 0)
    return (false);
  zc_handle_ok(this);
  return (true);
}
