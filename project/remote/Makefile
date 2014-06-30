##
## Makefile for zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Mon May 12 13:50:57 2014 raphael defreitas
## Last update Mon Jun 30 22:05:43 2014 raphael defreitas
##

CC		?=	clang

NAME		=	remote

SOURCES		=	$(shell find ./sources -name "*.c")

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -ansi -pedantic -g
CFLAGS		+=	-I ./headers
CFLAGS		+=	-I ./../libraries/liblist/headers
CFLAGS		+=	-I ./../libraries/libmy/headers
CFLAGS		+=	-I ./../libraries/libsocket/headers
CFLAGS		+=	-I ./../libraries/libzappy/headers
CFLAGS		+=	$(shell pkg-config --cflags glib-2.0)

LFLAGS		=
LFLAGS		+=	-L ./../libraries/libmy -l my
LFLAGS		+=	-L ./../libraries/libzappy -l zappy
LFLAGS		+=	-L ./../libraries/liblist -l list
LFLAGS		+=	-L ./../libraries/libsocket -l socket
LFLAGS		+=	-lm $(shell pkg-config --libs openssl)

all		:	$(NAME)

$(NAME)		:	$(OBJECTS)
			$(CC) -o $(NAME) $(OBJECTS) $(LFLAGS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all
