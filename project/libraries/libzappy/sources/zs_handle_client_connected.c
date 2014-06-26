/*
** zs_handle_client_connected.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Thu Jun 26 14:44:24 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zs_handle_client_connected(t_zs *this, t_zc *zc)
{
  t_zh		zh;

  if (this == NULL)
    return ;
  zh = this->hooks[ZHT_CLIENT_CONNECTED];
  if (zh.handler)
    zh.handler(this, zc, zh.data);
  zs_handle_callback(this, ZHT_CLIENT_CONNECTED);
}
