/*
** remote_stdin_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Wed Jul  2 02:36:17 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"zappy.h"

void		remote_stdin_handler(t_zc *zc,
				     const char *str,
				     __attribute__((unused))void *data)
{
  if (strcmp(str, "exit") == 0)
    {
      zc_hook_callback(zc, NULL, data);
      zc_disconnect(zc);
      return ;
    }
  else if (strcmp(str, "stop") == 0)
    {
      zc_send_rmt_stop(zc);
      return ;
    }
  else
    {
      printf("Command not found\nzappy > ");
      fflush(stdout);
      return ;
    }
}
