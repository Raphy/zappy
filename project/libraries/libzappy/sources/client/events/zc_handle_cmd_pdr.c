/*
** zc_handle_cmd_pdr.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Fri Jul 11 23:24:16 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_pdr(t_zc *this, t_pdr *pdr)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_PDR];
  if (zh.handler)
    zh.handler(this, pdr, zh.data);
  zc_handle_callback(this, ZHT_CMD_PDR);
}
