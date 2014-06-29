/*
** remote_cmd_welcome_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Sun Jun 29 20:11:46 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"zappy.h"

void		remote_disconnected_handler(__attribute__((unused))t_zc *zc,
					    __attribute__((unused))void *data)
{
  printf("Disconnected from server!\n");
}
