/*
** zs_treat_zc.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 17:10:00 2014 raphael defreitas
** Last update Sat Jun 28 03:39:29 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_treat_zc(t_zs *this, t_zc *zc)
{
  char		*command;

  if (list_length(zc->pckts_rcvd) == 0)
    return ;
  printf("Parsing the command...\n");
  if (zt_get_command(zc->pckts_rcvd, &command) == RET_FAILURE)
    zs_handle_errno(this, "command parsing failed");
  else if (command != NULL)
    {
      printf("COMMAND: %s\n", command);
      free(command);
    }
}
