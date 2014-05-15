/*
** zs_get_timeout.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 10:31:59 2014 raphael defreitas
** Last update Thu May 15 10:32:29 2014 raphael defreitas
*/

#include	"zappy.h"

t_timeval	zs_get_timeout(t_zs *this)
{
  return (this->timeout);
}
