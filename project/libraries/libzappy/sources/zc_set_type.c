/*
** zc_set_type.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 16:14:29 2014 raphael defreitas
** Last update Thu Jun 26 16:15:17 2014 raphael defreitas
*/


#include	<stdlib.h>

#include	"zappy.h"

void		zc_set_type(t_zc *this, t_zct type)
{
  if (this == NULL)
    return ;
  this->type = type;
}
