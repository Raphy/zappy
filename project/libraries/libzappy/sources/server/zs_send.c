/*
** zs_send.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:06:55 2014 raphael defreitas
** Last update Fri Jun 27 19:08:17 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send(t_zs *this, t_zc *zc, const char *packet)
{
  if (zc == NULL)
    zs_send_to_all(this, packet);
  else
    zs_send_to_client(this, zc, packet);
}
