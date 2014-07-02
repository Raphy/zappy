/*
** zs_send.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:06:55 2014 raphael defreitas
** Last update Tue Jul  1 19:30:56 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<string.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send(t_zs *this, t_zc *zc, const char *packet)
{
  char		*tmp;

  if ((tmp = strdup(packet)) == NULL)
    return ;
  if (zc == NULL)
    zs_send_to_all(this, tmp);
  else
    zs_send_to_client(this, zc, tmp);
}
