/*
** zc_hook_cmd_pdr.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Fri Jul 11 23:23:46 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_hook_cmd_pdr(t_zc *this, t_zch_cmd_pdr h, void *d)
{
  if (this == NULL)
    return ;
  zc_hook(this, ZHT_CMD_PDR, h, d);
}
