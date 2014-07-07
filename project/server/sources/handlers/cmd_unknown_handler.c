/*
** cmd_unknown_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Sun Jul  6 10:48:05 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"
#include	"_zappy.h"

void		cmd_unknown_handler(__attribute__((unused))t_zs *zs,
				    __attribute__((unused))t_zc *zc,
				    const char *cmd,
				    __attribute__((unused))void *data)
{
  t_msz		msz;
  t_bct		bct;

  printf("Unknown command: [%s]\n", cmd);
  msz.width = 123456789;
  msz.height = 987654321;
  zs_send_cmd_msz(zs, zc, msz);
  bct.position.x = 123;
  bct.position.y = 456;
  bct.food = 7;
  bct.linemate = 1;
  bct.deraumere = 2;
  bct.sibur = 3;
  bct.mendiane = 4;
  bct.phiras = 5;
  bct.thystame = 6;
  zs_send_cmd_bct(zs, zc, bct);
  //zc_disconnect(zc);
  //zs_send(zs, NULL, cmd); /* PRIVATE fucntion, only for test*/
  //zs_send(zs, NULL, "\n"); /* PRIVATE fucntion, only for test*/
}
