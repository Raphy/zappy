/*
** zs_treat_zc.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 17:10:00 2014 raphael defreitas
** Last update Sun Jun 29 06:21:42 2014 raphael defreitas
*/

#include	<stdio.h>

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_treat_zc(t_zs *this, t_zc *zc)
{
  char		*command;
  int		ret;

  if (list_length(zc->pckts_rcvd) == 0)
    return ;
  command = NULL;
  while ((ret = zt_build_command(zc->pckts_rcvd, &command)) == RET_SUCCESS &&
	 command != NULL)
    {
      printf("COMMAND: %s\n", command);
      zs_dispatch_command(this, zc, command);
      free(command);
      command = NULL;
    }
  if (ret == RET_FAILURE)
    zs_handle_errno(this, "command parsing failed");
}
