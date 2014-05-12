/*
** socket_accept.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Apr 15 00:03:17 2014 raphael defreitas
** Last update Sat Apr 19 02:33:15 2014 raphael defreitas
*/

#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<stdlib.h>

#include	"socket.h"

t_socket	*socket_accept(t_socket *this)
{
  t_socket	*client;

  if ((client = socket_new()) == NULL)
    return (NULL);
  client->addr_len = sizeof(struct sockaddr_in);
  client->fd = accept(this->fd, (struct sockaddr *)&client->addr,
		      &client->addr_len);
  return (client);
}
