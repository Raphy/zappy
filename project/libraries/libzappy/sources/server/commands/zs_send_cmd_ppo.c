/*
** zs_send_cmd_ppo.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Thu Jul 10 01:08:37 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_ppo(t_zs *this, t_zc *zc, const t_ppo *ppo)
{
  char		buf[100];

  if (this == NULL)
    return ;
  sprintf(buf, "ppo %u %u %u %u\n", ppo->uid, ppo->position.x, ppo->position.y,
	  ppo->orientation);
  zs_send(this, zc, buf);
}
