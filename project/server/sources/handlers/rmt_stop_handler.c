/*
** rmt_stop_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Tue Jul  1 15:58:52 2014 raphael defreitas
*/

#include	"zappy.h"

void		rmt_stop_handler(t_zs *zs,
				 t_zc *zc,
				 __attribute__((unused))void *data)
{
  zc_disconnect(zc);
  zs_stop(zs);
}
