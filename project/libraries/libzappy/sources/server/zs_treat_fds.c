/*
** zs_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 14:29:15 2014 raphael defreitas
** Last update Sat Jul 12 20:45:10 2014 raphael defreitas
*/

#include	<sys/select.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zs_treat_fds(t_zs *this)
{
  t_iterator	it;
  t_zc		*zc;

  if (FD_ISSET(socket_fd(this->socket), &this->rfds))
    zs_treat_client_connection(this);
  iterator_ctor(&it, this->clients, IT_DATA);
  while ((zc = iterator_current(&it)))
    {
      iterator_next(&it);
      if (FD_ISSET(socket_fd(zc->socket), &this->rfds))
	zs_treat_read_zc(this, zc);
      if (FD_ISSET(socket_fd(zc->socket), &this->wfds))
	zs_treat_write_zc(this, zc);
      zs_treat_zc(this, zc);
    }
  iterator_dtor(&it);
}
