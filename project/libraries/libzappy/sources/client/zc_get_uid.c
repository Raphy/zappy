/*
** zc_get_uid.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/client
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Jul  9 18:54:22 2014 raphael defreitas
** Last update Wed Jul  9 18:54:49 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

unsigned int	zc_get_uid(t_zc *this)
{
  if (this == NULL)
    return (0);
  return (this->uid);
}
