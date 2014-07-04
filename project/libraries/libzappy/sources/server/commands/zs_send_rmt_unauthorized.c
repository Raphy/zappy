/*
** zs_send_rmt_unauthorized.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Fri Jul  4 00:08:56 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_rmt_unauthorized(t_zs *this, t_zc *zc)
{
  if (this == NULL)
    return ;
  zs_send(this, zc, "RMT UNAUTHORIZED\n");
}
