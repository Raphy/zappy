/*
** zc_disconnect.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 18:08:49 2014 raphael defreitas
** Last update Mon Jun 30 17:46:22 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>

#include	"zappy.h"

void		zc_disconnect(t_zc *this)
{
  if (this == NULL)
    return ;
  this->has_to_disconnect = true;
  this->has_to_stop = true;
}
