/*
** zs_send_team_slot.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sun Jul 13 00:53:15 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_team_slots(t_zs *this, t_zc *zc, unsigned int team_slots)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "%u\n", team_slots);
  zs_send(this, zc, buf);
}
