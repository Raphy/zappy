/*
** zc_get_timeout.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:30:09 2014 raphael defreitas
** Last update Thu Jun 26 11:47:44 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

t_timeval	zc_get_timeout(t_zc *this)
{
  t_timeval	timeout;

  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  if (this != NULL)
    timeout = this->timeout;
  return (timeout);
}
