/*
** remote_set_handlers.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:01:11 2014 raphael defreitas
** Last update Wed Jul  2 04:10:51 2014 raphael defreitas
*/

#include	"remote.h"
#include	"zappy.h"

void		remote_set_handlers(t_remote *this)
{
  zc_hook_errno(this->zc, &remote_errno_handler, this);
  zc_hook_connected(this->zc, &remote_connected_handler, this);
  zc_hook_disconnected(this->zc, &remote_disconnected_handler, this);
  zc_hook_timeout(this->zc, &remote_timeout_handler, this);
}
