/*
** list_delete.c for liblist in /home/raphy/Epitech/Libraries/liblist
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Wed Apr 30 13:48:49 2014 raphael defreitas
** Last update Sun Jun 29 06:26:41 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		list_delete(t_list *this)
{
  if (this == NULL)
    return ;
  list_dtor(this);
  free(this);
}
