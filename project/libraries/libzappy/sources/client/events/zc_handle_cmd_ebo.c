/*
** zc_handle_cmd_ebo.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sat Jul 12 16:34:50 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_ebo(t_zc *this, unsigned int eid)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_EBO];
  if (zh.handler)
    zh.handler(this, eid, zh.data);
  zc_handle_callback(this, ZHT_CMD_EBO);
}
