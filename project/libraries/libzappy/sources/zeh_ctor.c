/*
** zeh_ctor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 14:24:01 2014 raphael defreitas
** Last update Mon May 12 14:40:34 2014 raphael defreitas
*/

#include	"zappy.h"

int		zeh_ctor(t_zeh *this, t_zet type, int (*handler)(), void *data)
{
  this->type = type;
  this->handler = handler;
  this->data = data;
  return (RET_SUCCESS);
}
