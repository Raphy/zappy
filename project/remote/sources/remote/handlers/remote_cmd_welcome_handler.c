/*
** remote_cmd_welcome_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Tue Jul  1 04:34:59 2014 raphael defreitas
*/

#include	"remote.h"
#include	"zappy.h"

void		remote_cmd_welcome_handler(t_zc *zc,
					   __attribute__((unused))void *data)
{
  zc_send_rmt(zc);
  zc_hook_rmt_pubkey(zc, &remote_rmt_pubkey_handler, data);
}
