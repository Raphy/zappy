/*
** cmd_rmt_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Tue Jul  1 03:50:50 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"

void		cmd_rmt_handler(t_zs *zs,
				t_zc *zc,
				__attribute__((unused))void *data)
{
  printf("[%d] is remote\n", zc->socket->fd);
  if (zs->public_key == NULL || zs->private_key == NULL)
    {
      printf("No RSA key pairing found!\n");
      zc_disconnect(zc);
    }
  else
    zs_send_rmt_pubkey(zs, zc);
}
