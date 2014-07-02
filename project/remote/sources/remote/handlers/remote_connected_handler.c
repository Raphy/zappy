/*
** remote_cmd_welcome_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Wed Jul  2 02:24:22 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"remote.h"
#include	"zappy.h"

void		remote_connected_handler(t_zc *zc,
					 void *data)
{
  printf("Connected to server!\n\n");
  zc_hook_cmd_welcome(zc, &remote_cmd_welcome_handler, data);
}
