/*
** callback_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Fri Jun 27 19:43:42 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		callback_handler(__attribute__((unused))t_zs *zs, t_zht type,
				 __attribute__((unused))void *data)
{
  printf("Callback handler (type:%d)\n", type);
}
