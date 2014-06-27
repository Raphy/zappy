##
## Makefile for libsocket in /home/raphy/Development/Epitech/Libraries/libsocket
##
## Made by Raphael De Freitas
## Login   <defrei_r@epitech.net>
##
## Started on  Mon Dec 16 00:00:03 2013 Raphael De Freitas
## Last update Fri Jun 27 20:29:40 2014 Barthelemy Delemotte
##

CC		?=	clang

NAME		=	libsocket.a

SOURCES		=	sources/socket_accept.c sources/socket_bind.c sources/socket_connect.c sources/socket_ctor.c sources/socket_delete.c sources/socket_dtor.c sources/socket_fd.c sources/socket_ip.c sources/socket_listen.c sources/socket_new.c sources/socket_read.c sources/socket_write.c

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -ansi -pedantic -fPIC
CFLAGS		+=	-I ./headers
CFLAGS		+=	$(shell pkg-config --cflags glib-2.0)

all		:	$(NAME)

$(NAME)		:	$(OBJECTS)
			ar rsc $(NAME) $(OBJECTS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.phony		:	all clean fclean re
