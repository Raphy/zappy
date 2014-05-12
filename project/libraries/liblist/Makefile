##
## Makefile for liblist in /home/raphy/Epitech/Libraries/liblist
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Thu Apr 17 18:52:55 2014 raphael defreitas
## Last update Mon May 12 13:53:25 2014 raphael defreitas
##

CC		?=	clang

NAME		=	liblist.a

SOURCES		=	sources/item_ctor.c sources/item_data.c sources/item_delete.c sources/item_dtor.c sources/item_new.c sources/item_next.c sources/item_prev.c sources/iterator_ctor.c sources/iterator_current.c sources/iterator_dtor.c sources/iterator_new.c sources/iterator_next.c sources/iterator_prev.c sources/iterator_reset.c sources/list_back.c sources/list_ctor.c sources/list_delete.c sources/list_dtor.c sources/list_dump.c sources/list_enqueue.c sources/list_find.c sources/list_front.c sources/list_length.c sources/list_new.c sources/list_push.c sources/list_unlink.c

OBJECTS		=	$(SOURCES:.c=.o)

CFLAGS		=	-Wall -Wextra -ansi -pedantic
CFLAGS		+=	-I ./headers
CFLAGS		+=	$(shell pkg-config --cflags glib-2.0)

LFLAGS		=	

all		:	$(NAME)

$(NAME)		:	$(OBJECTS)
			ar rsc $(NAME) $(OBJECTS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.phony		:	all clean fclean re
