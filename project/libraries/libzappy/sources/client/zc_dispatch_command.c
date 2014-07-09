/*
** zc_dispatch_command.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 05:45:16 2014 raphael defreitas
** Last update Wed Jul  9 23:59:07 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zc_dispatch_command(t_zc *this, const char *cmd)
{
  t_iterator	it;
  t_zc_cmd	cmd_fptr;

  printf("[libzappy] command: [%s]\n", cmd);
  iterator_ctor(&it, this->cmd_fptrs, IT_DATA);
  while ((cmd_fptr = (t_zc_cmd)iterator_current(&it)))
    {
      if (cmd_fptr(this, cmd))
	break;
      iterator_next(&it);
    }
  iterator_dtor(&it);
  if (cmd_fptr == NULL)
    zc_handle_cmd_unknown(this, cmd);
}
