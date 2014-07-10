/*
** zs_send_cmd_pin.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Thu Jul 10 01:32:17 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_pin(t_zs *this, t_zc *zc, const t_pin *pin)
{
  char		buf[100];

  if (this == NULL)
    return ;
  sprintf(buf, "pin %u %u %u %u %u %u %u %u %u %u\n", pin->uid,
	  pin->position.x, pin->position.y, pin->items.food,
	  pin->items.linemate, pin->items.deraumere, pin->items.sibur,
	  pin->items.mendiane, pin->items.phiras, pin->items.thystame);
  zs_send(this, zc, buf);
}
