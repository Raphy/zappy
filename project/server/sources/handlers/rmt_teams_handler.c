/*
** rmt_teams_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Mon Jul  7 10:54:40 2014 raphael defreitas
*/

#include	"zappy.h"

void		rmt_teams_handler(__attribute__((unused))t_zs *zs,
				  __attribute__((unused))t_zc *zc,
				  __attribute__((unused))void *data)
{
  t_list	test;

  list_ctor(&test, NULL);
  list_push(&test, "team#1");
  list_push(&test, "team#2");
  zs_send_rmt_teams(zs, zc, &test);
  list_dtor(&test);
}
