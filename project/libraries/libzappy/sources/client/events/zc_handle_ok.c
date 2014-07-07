/*
** zc_handle_ok.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sun Jul  6 18:53:19 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_ok(t_zc *this)
{
  t_zh		zh;

  zh = this->hooks[ZHT_OK];
  if (zh.handler)
    zh.handler(this, zh.data);
  zc_handle_callback(this, ZHT_OK);
}
