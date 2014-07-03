/*
** remote_rmt_pubkey_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Fri Jul  4 00:32:11 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"remote.h"
#include	"zappy.h"

void		remote_rmt_pubkey_handler(t_zc *zc,
					  __attribute__((unused))const char *pk,
					  void *data)
{
  zc_send_rmt_pubkey(zc);
  printf("Waiting server authentication...\n");
  zc_hook_rmt_authorized(zc, &remote_rmt_authorized_handler, data);
  zc_hook_rmt_unauthorized(zc, &remote_rmt_unauthorized_handler, data);
}
