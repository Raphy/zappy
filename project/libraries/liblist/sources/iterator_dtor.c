/*
** iterator_dtor.c for liblist in /home/raphy/Epitech/Tech_2/PSU_2013_myirc/libs/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Apr 20 01:58:10 2014 raphael defreitas
** Last update Sun Apr 20 01:59:04 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"

void		iterator_dtor(t_iterator *this)
{
  this->list = NULL;
  this->current = NULL;
}
