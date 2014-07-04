/*
** remote_rmt_unauthorized.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jul  4 00:27:00 2014 raphael defreitas
** Last update Fri Jul  4 00:36:33 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		remote_rmt_unauthorized_handler(t_zc *zc,
						__attribute__((unused))void *d)
{
  printf("Authentication refused\n");
  zc_disconnect(zc);
}
