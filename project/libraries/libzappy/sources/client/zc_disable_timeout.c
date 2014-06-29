/*
** zc_disable_timeout.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:30:50 2014 raphael defreitas
** Last update Thu Jun 26 11:46:17 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zc_disable_timeout(t_zc *this)
{
  if (this == NULL)
    return ;
  zc_set_timeout(this, 0, 0);
}
