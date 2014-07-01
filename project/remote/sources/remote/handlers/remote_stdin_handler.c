/*
** remote_stdin_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Tue Jul  1 05:02:34 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		remote_stdin_handler(t_zc *zc,
				     const char *str,
				     __attribute__((unused))void *data)
{
  char		*b64_encoded;
  /*char		*b64_decoded;*/
  unsigned char	*encrypted;
  int		encrypted_len;

  if (strcmp(str, "exit") == 0)
    {
      zc_hook_callback(zc, NULL, data);
      zc_disconnect(zc);
      return ;
    }
  encrypted = zt_rsa_encrypt(zc->pubkey, str, &encrypted_len);
  b64_encoded = zt_b64_encode((unsigned char *)str, encrypted_len);
  /*b64_decoded = zt_b64_decode(b64_encoded);*/
  printf("STDIN: [%s] [%s]\n", str, b64_encoded);
  free(b64_encoded);
  free(encrypted);
  /*free(b64_decoded);*/
}
