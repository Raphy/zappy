/*
** zs_dispatch_command.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 05:45:16 2014 raphael defreitas
** Last update Sun Jun 29 06:48:14 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zs_dispatch_command(t_zs *this, t_zc *zc, const char *cmd)
{
  t_iterator	it;
  t_zs_cmd	cmd_fptr;

  iterator_ctor(&it, this->cmd_fptrs, IT_DATA);
  while ((cmd_fptr = (t_zs_cmd)iterator_current(&it)))
    {
      if (cmd_fptr(this, zc, cmd))
	break;
      iterator_next(&it);
    }
  iterator_dtor(&it);
  if (cmd_fptr == NULL)
    zs_handle_cmd_unknown(this, zc, cmd);
}
