/*
** remote_rmt_teams_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Mon Jul  7 10:52:26 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"remote.h"
#include	"zappy.h"

void		remote_rmt_teams_handler(t_zc *zc,
					 const char *teams,
					 __attribute__((unused))void *data)
{
  printf("Teams: %s\n", teams);
  zc_disable_timeout(zc);
}
