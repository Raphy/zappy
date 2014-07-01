/*
** zs_treat_zc.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 17:10:00 2014 raphael defreitas
** Last update Tue Jul  1 19:35:34 2014 raphael defreitas
*/

#include	<stdio.h>

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

static void	treat_commands(t_zs *this, t_zc *zc)
{
  char		*cmd;

  if (list_length(zc->commands) == 0)
    return ;
  while ((cmd = list_pop(zc->commands)))
    {
      zs_dispatch_command(this, zc, cmd);
      free(cmd);
    }
}

void		zs_treat_zc(t_zs *this, t_zc *zc)
{
  char		*command;
  int		ret;

  if (list_length(zc->pckts_rcvd) == 0)
    return ;
  command = NULL;
  ret = RET_SUCCESS;
  while ((ret = zt_build_command(zc->pckts_rcvd, &command)) == RET_SUCCESS &&
	 command != NULL)
    {
      printf("PTR: %p\n", (void *)command);
      if (list_enqueue(zc->commands, command) == RET_FAILURE)
	zs_handle_errno(this, "command storing failed");
      if (list_length(zc->commands) >= 10)
	list_clear(zc->pckts_rcvd);
      command = NULL;
    }
  if (ret == RET_FAILURE)
    zs_handle_errno(this, "command parsing failed");
  else
    treat_commands(this, zc);
}
