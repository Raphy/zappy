/*
** list_dump.c for liblist in /home/raphy/Epitech/Tech_2/Librairies/liblist/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Apr 20 01:41:35 2014 raphael defreitas
** Last update Sun Apr 20 02:02:58 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"list.h"

void		list_dump(t_list *this)
{
  t_iterator	iterator;
  t_item	*item;

  printf("+---------------------------+\n");
  printf("| List dump < %p > |\n", (void *)this);
  printf("+---------------------------+\n");
  printf("Length: %lu\n", list_length(this));
  printf("Front: %p - Back: %p\n", (void *)this->front, (void *)this->back);
  iterator_ctor(&iterator, this, IT_ITEM);
  while ((item = iterator_current(&iterator)))
    {
      iterator_next(&iterator);
      printf("%p < %p > %p\n", (void *)item->prev, (void *)item,
	     (void *)item->next);
    }
}
