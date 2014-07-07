/*
** callback_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Fri Jun 27 19:43:42 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

char    tab[32][50] = {
  "ZHT_UNKNOWN",
  "ZHT_ERRNO",
  "ZHT_CALLBACK",
  "ZHT_CLIENT_CONNECTED",
  "ZHT_CLIENT_DISCONNECTED",
  "ZHT_TIMEOUT",
  "ZHT_BEFORE_SELECT",
  "ZHT_AFTER_SELECT",
  "ZHT_STDIN",
  "ZHT_OK",
  "ZHT_KO",
  "ZHT_CMD_MIN",
  "ZHT_CMD_UNKNOWN",
  "ZHT_CMD_WELCOME",
  "ZHT_CMD_TEAM_NAME",
  "ZHT_CMD_FORWARD",
  "ZHT_CMD_LEFT",
  "ZHT_CMD_RIGHT",
  "ZHT_CMD_GRAPHIC",
  "ZHT_CMD_MSZ",
  "ZHT_CMD_BCT",
  "ZHT_CMD_MCT",
  "ZHT_CMD_RMT",
  "ZHT_CMD_MAX",
  "ZHT_RMT_MIN",
  "ZHT_RMT_AUTHORIZED",
  "ZHT_RMT_UNAUTHORIZED",
  "ZHT_RMT_PUBKEY",
  "ZHT_RMT_STOP",
  "ZHT_RMT_TEAMS",
  "ZHT_RMT_MAX",
  "ZHT_MAX"
};

void		callback_handler(__attribute__((unused))t_zs *zs, t_zht type,
				 __attribute__((unused))void *data)
{
  printf("Callback handler %s (type:%d)\n", tab[type], type);
}
