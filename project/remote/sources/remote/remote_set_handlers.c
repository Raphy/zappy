/*
** remote_set_handlers.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:01:11 2014 raphael defreitas
** Last update Mon Jun 30 17:20:49 2014 raphael defreitas
*/

#include	"remote.h"
#include	"zappy.h"

void		remote_set_handlers(t_remote *this)
{
  zc_hook_errno(this->zc, &remote_errno_handler, this);
  zc_hook_connected(this->zc, &remote_connected_handler, this);
  zc_hook_disconnected(this->zc, &remote_disconnected_handler, this);
  zc_hook_stdin(this->zc, &remote_stdin_handler, this);
  zc_hook_cmd_welcome(this->zc, &remote_cmd_welcome_handler, this);
}
