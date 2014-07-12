/*
** zs_cmd_msz.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jul  5 15:48:50 2014 raphael defreitas
** Last update Sat Jul 12 14:13:54 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

bool		zs_cmd_msz(t_zs *this, t_zc *zc, const char *cmd)
{
  printf("Checking [MSZ]\n");
  if (strcmp(cmd, "msz") != 0)
    return (false);
  printf("IS MSZ!\n");
  zs_handle_cmd_msz(this, zc);
  return (true);
}
