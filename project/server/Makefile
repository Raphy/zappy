##
## Makefile for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Mon May 12 13:50:57 2014 raphael defreitas
## Last update Mon May 12 16:13:26 2014 raphael defreitas
##

CC		?=	clang

NAME		=	server

SOURCES		=	$(shell find ./sources -name "*.c")

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -ansi -pedantic
CFLAGS		+=	-I ./headers
CFLAGS		+=	-I ./../libraries/liblist/headers
CFLAGS		+=	-I ./../libraries/libsocket/headers
CFLAGS		+=	-I ./../libraries/libzappy/headers
CFLAGS		+=	$(shell pkg-config --cflags glib-2.0)

LFLAGS		=	-L ./../libraries/libzappy -l zappy
LFLAGS		+=	-L ./../libraries/liblist -l list
LFLAGS		+=	-L ./../libraries/libsocket -l socket

all		:	kikoo_start $(NAME) kikoo_end

kikoo_start	:
			@echo -e "\e[1;32mCompiling « server »...\e[0;32m"
kikoo_end	:
			@echo -en "\e[0m"

$(NAME)		:	$(OBJECTS)
			$(CC) -o $(NAME) $(OBJECTS) $(LFLAGS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean	all
