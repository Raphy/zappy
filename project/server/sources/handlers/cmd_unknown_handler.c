/*
** cmd_unknown_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Sun Jul 13 07:45:55 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"
#include	"_zappy.h"

void		cmd_unknown_handler(__attribute__((unused))t_zs *zs,
				    __attribute__((unused))t_zc *zc,
				    __attribute__((unused))const char *cmd,
				    __attribute__((unused))void *data)
{
  t_zct		type;

  type = zc_get_type(zc);
  if (type == ZCT_UNKNOWN)
    zc_disconnect(zc);
  else if (type == ZCT_GRAPHIC)
    zs_send_cmd_suc(zs, zc);
  else if (type == ZCT_PLAYER)
    {
      zs_send_ko(zs, zc);
      zc_disconnect(zc);
    }
}
