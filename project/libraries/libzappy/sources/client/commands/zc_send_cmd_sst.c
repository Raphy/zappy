/*
** zc_send_cmd_sst.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 10:07:53 2014 raphael defreitas
** Last update Thu Jul 10 03:07:43 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_send_cmd_sst(t_zc *this, unsigned int time)
{
  char		buf[50];

  if (this == NULL)
    return ;
  sprintf(buf, "sst %u\n", time);
  zc_send(this, buf);
}
