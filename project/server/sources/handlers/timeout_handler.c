/*
** timeout_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:29:56 2014 raphael defreitas
** Last update Sat Jun 28 23:01:20 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		timeout_handler(t_zs *zs,
				__attribute__((unused))void *data)
{
  printf("timeout handler\n");
  zs_disable_timeout(zs);
}
