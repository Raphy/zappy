/*
** item_dtor.c for liblist in /home/raphy/Epitech/Libraries/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Apr 17 19:18:27 2014 raphael defreitas
** Last update Sun Jun 29 06:25:04 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		item_dtor(t_item *this)
{
  if (this == NULL)
    return ;
  if (this->data_free_fptr)
    this->data_free_fptr(this->data);
  this->data = NULL;
  this->next = NULL;
  this->prev = NULL;
  this->data_free_fptr = NULL;
}
