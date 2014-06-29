/*
** zs_set_timeout.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:28:53 2014 raphael defreitas
** Last update Thu Jun 26 11:34:42 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<sys/time.h>

#include	"zappy.h"

void		zs_set_timeout(t_zs *this, time_t sec, suseconds_t usec)
{
  if (this == NULL)
    return ;
  this->timeout.tv_sec = sec;
  this->timeout.tv_usec = usec;
}
