/*
** remote_rmt_authorized.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jul  4 00:24:30 2014 raphael defreitas
** Last update Mon Jul  7 10:47:01 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"remote.h"
#include	"zappy.h"

void		remote_rmt_authorized_handler(t_zc *zc,
					      void *data)
{
  printf("Authenticated.\n\n");
  zc_hook_stdin(zc, &remote_stdin_handler, data);
  zc_hook_callback(zc, &remote_callback_handler, data);
  zc_hook_rmt_teams(zc, &remote_rmt_teams_handler, data);
}
