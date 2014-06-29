/*
** cmd_unknown_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:29:56 2014 raphael defreitas
** Last update Sun Jun 29 06:56:56 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		cmd_unknown_handler(__attribute__((unused))t_zc *zc,
				    const char *cmd,
				    __attribute__((unused))void *data)
{
  printf("Unknown command [%s]\n", cmd);
}
