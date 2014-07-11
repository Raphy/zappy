/*
** remote_stdin_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Wed Jul  2 04:16:44 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"zappy.h"

void		remote_stdin_handler(t_zc *zc,
				     const char *str,
				     void *data)
{
  zc_hook_stdin(zc, NULL, NULL);
  zc_set_timeout(zc, 5, 0);
  if (strcmp(str, "exit") == 0)
    {
      zc_hook_callback(zc, NULL, NULL);
      zc_disconnect(zc);
    }
  else if (strcmp(str, "stop") == 0)
    zc_send_rmt_stop(zc);
  else if (strcmp(str, "teams") == 0)
    zc_send_rmt_teams(zc);
  else
    {
      zc_disable_timeout(zc);
      zc_hook_stdin(zc, &remote_stdin_handler, data);
      printf("Command not found\nzappy > ");
      fflush(stdout);
      return ;
    }
}
