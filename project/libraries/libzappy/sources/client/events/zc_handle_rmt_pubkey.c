/*
** zc_handle_rmt_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Tue Jul  1 03:41:18 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_rmt_pubkey(t_zc *this, const char *pubkey)
{
  t_zh		zh;

  zh = this->hooks[ZHT_RMT_PUBKEY];
  if (zh.handler)
    zh.handler(this, pubkey, zh.data);
  zc_handle_callback(this, ZHT_RMT_PUBKEY);
}
