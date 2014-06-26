/*
** zc_handle_timeout.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Thu Jun 26 13:31:50 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zc_handle_timeout(t_zc *this)
{
  t_zh		zh;

  if (this == NULL)
    return ;
  zh = this->hooks[ZHT_TIMEOUT];
  if (zh.handler)
    zh.handler(this, zh.data);
  zc_handle_callback(this, ZHT_TIMEOUT);
}
