##
## Makefile for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Mon May 12 12:31:25 2014 raphael defreitas
## Last update Mon Jun 30 22:04:30 2014 raphael defreitas
##

CC		?=	clang

NAME		=	libzappy.a

SOURCES		=	$(shell find ./sources -name "*.c")

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -ansi -pedantic -g -fPIC
CFLAGS		+=	-I ./headers -I ./../libmy/headers -I ./../liblist/headers -I ./../libsocket/headers
CFLAGS		+=	$(shell pkg-config --cflags glib-2.0) $(shell pkg-config --cflags openssl)

LDFLAGS		=	-shared

all		:	$(NAME)

$(NAME)		:	$(OBJECTS)
			ar rsc $(NAME) $(OBJECTS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all
