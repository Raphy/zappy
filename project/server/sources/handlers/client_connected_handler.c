/*
** client_connected_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Fri Jun 27 19:33:09 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		client_connected_handler(t_zs *zs, t_zc *zc,
					 __attribute__((unused))void *data)
{
  printf("Client connected (fd:%d)\n", zc->socket->fd);
  zs_send_welcome(zs, zc);
}