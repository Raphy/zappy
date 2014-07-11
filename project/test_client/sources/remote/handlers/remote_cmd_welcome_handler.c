/*
** remote_cmd_welcome_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Thu Jul 10 05:18:00 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"remote.h"
#include	"zappy.h"

void		remote_cmd_welcome_handler(t_zc *zc,
					   __attribute__((unused))void *data)
{
  zc_send_graphic(zc);

  /*zc_hook_rmt_pubkey(zc, &remote_rmt_pubkey_handler, data);
    printf("Waiting the server public key...\n");*/
}
