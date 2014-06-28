/*
** zs_stop.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jun 28 04:11:20 2014 raphael defreitas
** Last update Sat Jun 28 04:11:58 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>

#include	"zappy.h"

void		zs_stop(t_zs *this)
{
  if (this == NULL)
    return ;
  this->has_to_stop = true;
}
