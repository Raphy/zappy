##
## Makefile for libmy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libmy
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Mon May 12 12:31:25 2014 raphael defreitas
## Last update Thu Jul  3 19:14:52 2014 raphael defreitas
##

CC		?=	clang

NAME		=	libmy.a

SOURCES		=	$(shell find ./sources -name "*.c")

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -ansi -g -fPIC
CFLAGS		+=	-I ./headers
CFLAGS		+=	$(shell pkg-config --cflags glib-2.0)

LDFLAGS		=	-shared

all		:	$(NAME)

$(NAME)		:	$(OBJECTS)
			ar rsc $(NAME) $(OBJECTS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all
