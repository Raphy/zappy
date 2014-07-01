/*
** zt_rmt_decrypt.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 16:10:46 2014 raphael defreitas
** Last update Tue Jul  1 16:25:43 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"

int		zt_rmt_decrypt(const char *cmd, char **plain)
{
  char		*tmp;
  char		*crypted_len;
  char		*encoded;
  unsigned char	*crypted;

  *plain = NULL;
  if ((tmp = strdup(cmd + 8)) == NULL)
    return (RET_FAILURE);
  
  return (RET_SUCCESS);
}
