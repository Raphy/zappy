/*
** zc_handle_cmd_pic.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sat Jul 12 11:45:15 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_pic(t_zc *this, t_pic *pic)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_PIC];
  if (zh.handler)
    zh.handler(this, pic, zh.data);
  zc_handle_callback(this, ZHT_CMD_PIC);
}
