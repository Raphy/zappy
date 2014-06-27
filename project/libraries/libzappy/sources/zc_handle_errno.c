/*
** zc_handle_errno.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Fri Jun 27 14:00:20 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_errno(t_zc *this)
{
  t_zh		zh;

  if (this == NULL)
    return ;
  zh = this->hooks[ZHT_ERRNO];
  if (zh.handler)
    zh.handler(this, errno, zh.data);
  zc_handle_callback(this, ZHT_ERRNO);
}
