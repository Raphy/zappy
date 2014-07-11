/*
** zs_send_cmd_pgt.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Fri Jul 11 23:48:12 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_send_cmd_pgt(t_zs *this, t_zc *zc, const t_pgt *pgt)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "pgt %u %u\n", pgt->uid, pgt->resource);
  zs_send(this, zc, buf);
}
