/*
** zs_set_timeout.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 10:31:07 2014 raphael defreitas
** Last update Thu May 15 10:31:53 2014 raphael defreitas
*/

#include	<sys/time.h>

#include	"zappy.h"

void		zs_set_timeout(t_zs *this, time_t sec, suseconds_t usec)
{
  this->timeout.tv_sec = sec;
  this->timeout.tv_usec = usec;
}
