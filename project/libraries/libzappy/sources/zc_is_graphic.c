/*
** zc_is_graphic.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 12:43:18 2014 raphael defreitas
** Last update Thu Jun 26 12:51:29 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

char		zc_is_graphic(t_zc *this)
{
  if (this == NULL)
    return (-1);
  return (this->is_graphic == 1);
}
