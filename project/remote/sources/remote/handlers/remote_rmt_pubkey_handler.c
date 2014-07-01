/*
** remote_rmt_pubkey_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Tue Jul  1 04:55:06 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"remote.h"
#include	"zappy.h"

void		remote_rmt_pubkey_handler(t_zc *zc,
					  __attribute__((unused))const char *pk,
					  __attribute__((unused))void *data)
{
  zc_hook_stdin(zc, &remote_stdin_handler, data);
  zc_hook_callback(zc, &remote_callback_handler, data);
}
