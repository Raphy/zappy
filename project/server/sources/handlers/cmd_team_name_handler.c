/*
** cmd_team_name_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Sun Jun 29 06:18:54 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		cmd_team_name_handler(__attribute__((unused))t_zs *zs,
				      __attribute__((unused))t_zc *zc,
				      const char *team_name,
				      __attribute__((unused))void *data)
{
  printf("Team Name [%s]\n", team_name);
}
