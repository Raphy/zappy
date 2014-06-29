/*
** my_str_is_numeric.c for libmy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libmy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 16:55:06 2014 raphael defreitas
** Last update Sun Jun 29 16:57:30 2014 raphael defreitas
*/

#include	<ctype.h>
#include	<stdbool.h>
#include	<stdlib.h>

bool		my_str_is_numeric(const char *str)
{
  int		i;

  if (str == NULL)
    return (false);
  i = 0;
  while (str[i] != '\0')
    {
      if (isdigit(str[i]) == 0)
	return (false);
      i++;
    }
  return (true);
}
