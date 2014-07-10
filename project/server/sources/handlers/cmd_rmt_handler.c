/*
** cmd_rmt_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Thu Jul 10 01:11:49 2014 damien sauvalle
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"handlers.h"
#include	"zappy.h"

void		cmd_rmt_handler(t_zs *zs,
				t_zc *zc,
				void *data)
{
  printf("RMT HANDLER \n");

  if (zc_get_type(zc) != ZCT_UNKNOWN)
    {
      zc_disconnect(zc);
      return ;
    }
  printf("[%d] is remote\n", zc->socket->fd);
  if (zs->key_encrypt == NULL || zs->key_decrypt == NULL)
    {
      printf("No RSA key pairing found!\n");
      zc_disconnect(zc);
      return ;
    }
  zc_set_type(zc, ZCT_RMT);
  zs_send_rmt_pubkey(zs, zc);
  zs_hook_rmt_pubkey(zc, &rmt_pubkey_handler, data);
}
