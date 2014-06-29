/*
** zc_get_type.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 16:13:31 2014 raphael defreitas
** Last update Thu Jun 26 16:14:15 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

t_zct		zc_get_type(t_zc *this)
{
  if (this == NULL)
    return (ZCT_UNKNOWN);
  return (this->type);
}
