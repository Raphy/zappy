/*
** zs_treat_zc.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 17:10:00 2014 raphael defreitas
** Last update Fri Jun 27 18:25:45 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_treat_zc(t_zs *this, t_zc *zc)
{
  if (this == NULL)
    return ;
  if (list_length(zc->pckts_rcvd) == 0)
    return ;
}
