/*
** zs_handler_new_client.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 11:11:53 2014 raphael defreitas
** Last update Thu May 15 11:14:54 2014 raphael defreitas
*/

#include	"zappy.h"

void		zs_handle_new_client(t_zs *this, t_zc *client)
{
  void		*data;
  void		(*handler)();

  handler = this->hooks[ZHT_NEW_CLIENT].handler;
  data = this->hooks[ZHT_NEW_CLIENT].data;
  if (handler)
    handler(this, client, data);
}
