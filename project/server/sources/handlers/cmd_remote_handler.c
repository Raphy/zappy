/*
** cmd_remote_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Sun Jun 29 19:31:23 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		cmd_remote_handler(__attribute__((unused))t_zs *zs,
				   t_zc *zc,
				   __attribute__((unused))void *data)
{
  printf("[%d] is remote\n", zc->socket->fd);
}
