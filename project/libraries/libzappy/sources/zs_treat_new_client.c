/*
** zs_treat_new_client.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 10:48:28 2014 raphael defreitas
** Last update Thu May 15 11:10:44 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/select.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

void		zs_treat_new_client(t_zs *this)
{
  t_zc		*client;

  if (FD_ISSET(socket_fd(this->socket), &this->rfds))
    {
      if ((client = zc_new()) == NULL)
	fprintf(stderr, "[ERROR] Cannot create new client\n");
      else if ((client->socket = socket_accept(this->socket)) == NULL)
	fprintf(stderr, "[ERROR] Cannot connect new client\n");
      else if (list_enqueue(&this->clients, client) == RET_FAILURE)
	fprintf(stderr, "[ERROR] Cannot enqueue the new client\n");
      else
	{
	  printf("[INFO] Client connected\n");
	  zs_handle_new_client(this, client);
	}
    }
}
