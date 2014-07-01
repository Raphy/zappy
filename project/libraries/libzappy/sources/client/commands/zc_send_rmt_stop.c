/*
** zc_send_rmt_stop.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/client/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 16:32:11 2014 raphael defreitas
** Last update Tue Jul  1 16:34:29 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_rmt_stop(t_zc *this)
{
  if (this == NULL)
    return ;
  zc_send(this, "RMT MSG 10 azerty\n");
}
