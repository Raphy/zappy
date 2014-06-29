/*
** my_match.c for libmy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libmy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 17:12:26 2014 raphael defreitas
** Last update Sun Jun 29 17:12:59 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdlib.h>

bool		my_match(const char *str, const char *pattern)
{
  if (str == NULL || pattern == NULL)
    return (false);
  if (*pattern != '*')
    {
      if (*str)
	return (*str == *pattern
		&& my_match(str + sizeof(char), pattern + sizeof(char)));
      else
	return (!*pattern);
    }
  return (my_match(str, pattern + sizeof(char))
	  || (*str && my_match(str + sizeof(char), pattern)));
}
