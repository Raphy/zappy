/*
** client_disconnected_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Fri Jun 27 19:32:59 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		client_disconnected_handler(__attribute__((unused))t_zs *zs,
					    t_zc *zc,
					    __attribute__((unused))void *data)
{
  printf("Client disconnected (fd:%d)\n", zc->socket->fd);
}
