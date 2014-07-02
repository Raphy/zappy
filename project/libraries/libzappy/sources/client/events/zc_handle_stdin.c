/*
** zc_handle_stdin.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Tue Jul  1 16:42:36 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_stdin(t_zc *this, const char *str)
{
  t_zh		zh;

  zh = this->hooks[ZHT_STDIN];
  if (zh.handler)
    zh.handler(this, str, zh.data);
}
