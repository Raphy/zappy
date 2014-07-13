/*
** zc_handle_cmd_edi.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sat Jul 12 16:35:43 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_edi(t_zc *this, unsigned int eid)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_EDI];
  if (zh.handler)
    zh.handler(this, eid, zh.data);
  zc_handle_callback(this, ZHT_CMD_EDI);
}
