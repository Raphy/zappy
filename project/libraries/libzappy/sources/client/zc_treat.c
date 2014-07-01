/*
** zc_treat.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/client
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jun 30 23:53:14 2014 raphael defreitas
** Last update Tue Jul  1 04:50:47 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

static void	treat_command(t_zc *this)
{
  char		*command;
  int		ret;

  if (list_length(this->pckts_rcvd) == 0)
    return ;
  command = NULL;
  while ((ret = zt_build_command(this->pckts_rcvd, &command)) == RET_SUCCESS &&
	 command != NULL)
    {
      zc_dispatch_command(this, command);
      free(command);
      command = NULL;
    }
  if (ret == RET_FAILURE)
    zc_handle_errno(this, "command parsing failed");
}

static void	treat_stdin_buffer(t_zc *this)
{
  char		*command;
  int		ret;

  if (list_length(this->stdin) == 0)
    return ;
  command = NULL;
  while ((ret = zt_build_command(this->stdin, &command)) == RET_SUCCESS &&
	 command != NULL)
    {
      zc_handle_stdin(this, command);
      free(command);
      command = NULL;
    }
  if (ret == RET_FAILURE)
    zc_handle_errno(this, "stdin parsing failed");
}

void		zc_treat(t_zc *this)
{
  treat_stdin_buffer(this);
  treat_command(this);
}
