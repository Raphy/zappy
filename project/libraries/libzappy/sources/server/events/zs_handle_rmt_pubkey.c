/*
** zs_handle_rmt_pubkey.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Wed Jul  2 15:48:04 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_rmt_pubkey(t_zs *this, t_zc *zc, const char *pubkey)
{
  t_zh		zh;

  zh = zc->hooks[ZHT_RMT_PUBKEY];
  if (zh.handler)
    zh.handler(this, zc, pubkey, zh.data);
  zs_handle_callback(this, ZHT_RMT_PUBKEY);
}
