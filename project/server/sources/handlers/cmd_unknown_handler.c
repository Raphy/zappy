/*
** cmd_unknown_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Mon Jul  7 17:52:18 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"
#include	"_zappy.h"

void		cmd_unknown_handler(__attribute__((unused))t_zs *zs,
				    __attribute__((unused))t_zc *zc,
				    const char *cmd,
				    __attribute__((unused))void *data)
{
  zc_disconnect(zc);
}
