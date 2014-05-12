##
## Makefile for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Mon May 12 13:50:57 2014 raphael defreitas
## Last update Mon May 12 14:07:52 2014 raphael defreitas
##

CC		?=	clang

NAME		=	server

SOURCES		=	$(shell find ./sources -name "*.c")

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -ansi -pedantic
CFLAGS		+=	-I ./headers

LFLAGS		=

all		:	kikoo_start $(NAME) kikoo_end

kikoo_start	:
			@echo -e "\e[1;32mCompiling « server »...\e[0;32m"
kikoo_end	:
			@echo -en "\e[0m"

$(NAME)		:	$(OBJECTS)
			$(CC) -o $(NAME) $(OBJECTS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean	all
