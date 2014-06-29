/*
** disconnected_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Sun Jun 29 03:03:19 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		disconnected_handler(__attribute__((unused))t_zc *zc,
				     __attribute__((unused))void *data)
{
  printf("Disconnected of server!\n");
}
