/*
** remote_ctor.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 19:00:47 2014 raphael defreitas
** Last update Sun Jun 29 19:01:38 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"my.h"
#include	"remote.h"
#include	"zappy.h"

int		remote_ctor(t_remote *this, t_zc *zc)
{
  if (this == NULL)
    return (RET_FAILURE);
  this->zc = zc;
  return (RET_SUCCESS);
}
