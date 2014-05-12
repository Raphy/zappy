/*
** iterator_new.c for list in /home/raphy/Epitech/Tech_2/PSU_2013_myirc/libs/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Apr 20 01:58:52 2014 raphael defreitas
** Last update Sun Apr 20 02:04:09 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

t_iterator	*iterator_new(t_list *list, t_it_type type)
{
  t_iterator	*this;

  if ((this = malloc(sizeof(t_iterator))) == NULL)
    return (NULL);
  iterator_ctor(this, list, type);
  return (this);
}
