/*
** zs_disable_timeout.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 10:32:40 2014 raphael defreitas
** Last update Thu May 15 10:33:07 2014 raphael defreitas
*/

#include	"zappy.h"

void		zs_disable_timeout(t_zs *this)
{
  zs_set_timeout(this, 0, 0);
}
