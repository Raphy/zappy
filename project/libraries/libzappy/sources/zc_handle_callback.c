/*
** zc_handle_callback.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Fri Jun 27 13:59:47 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zc_handle_callback(t_zc *this, t_zht type)
{
  t_zh		zh;

  if (this == NULL)
    return ;
  zh = this->hooks[ZHT_CALLBACK];
  if (zh.handler)
    zh.handler(this, type, zh.data);
}
