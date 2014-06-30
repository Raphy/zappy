/*
** remote_stdin_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Mon Jun 30 17:20:18 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		remote_stdin_handler(t_zc *zc,
				     const char *str,
				     __attribute__((unused))void *data)
{
  printf("STDIN: [%s]\n", str);
}
