/*
** zt_get_next_token.c for ZAppy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/tools
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jul 13 05:19:41 2014 raphael defreitas
** Last update Sun Jul 13 05:23:36 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"

unsigned int	zt_get_next_token(char **ptr, bool *has_error)
{
  char		*tok;
  char		*end;
  unsigned int	res;

  if (*has_error)
    return (0);
  tok = *ptr;
  end = strchr(tok, ' ');
  if (end)
    {
      tok[end - tok] = 0;
      end++;
    }
  *ptr = end;
  if (!my_str_is_numeric(tok))
    {
      *has_error = true;
      return (0);
    }
  res = strtoul(tok, NULL, 0);
  return (res);
}
