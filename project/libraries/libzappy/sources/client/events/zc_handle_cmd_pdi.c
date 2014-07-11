/*
** zc_handle_cmd_pdi.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sat Jul 12 00:15:14 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_pdi(t_zc *this, unsigned int uid)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_PDI];
  if (zh.handler)
    zh.handler(this, uid, zh.data);
  zc_handle_callback(this, ZHT_CMD_PDI);
}
