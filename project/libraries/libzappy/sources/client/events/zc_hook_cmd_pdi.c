/*
** zc_hook_cmd_pdi.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Sat Jul 12 00:15:06 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_hook_cmd_pdi(t_zc *this, t_zch_uint_basic h, void *d)
{
  if (this == NULL)
    return ;
  zc_hook(this, ZHT_CMD_PDI, h, d);
}
