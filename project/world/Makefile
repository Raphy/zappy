##
## Makefile for world in /home/marie/zappy/zappy/project/world
## 
## Made by lefebv_z
## Login   <marie@epitech.net>
## 
## Started on  Mon Jun 30 12:30:44 2014 lefebv_z
## Last update Mon Jun 30 16:22:10 2014 raphael defreitas
##

CXX		?=	clang++

NAME		=	world

SOURCES		=	$(shell find ./sources -name "*.cpp")

OBJECTS		=	$(SOURCES:.cpp=.o)

CXXFLAGS		=	-Wall -Wextra -ansi -pedantic -g
CXXFLAGS		+=	-I ./interfaces
CXXFLAGS		+=	-I ./../libraries/libmy/headers
CXXFLAGS		+=	-I ./../libraries/liblist/headers
CXXFLAGS		+=	-I ./../libraries/libsocket/headers
CXXFLAGS		+=	-I ./../libraries/libzappy/headers
CXXFLAGS		+=	$(shell pkg-config --cflags glib-2.0)
CXXFLAGS		+=	-isystem /usr/include/irrlicht #TODO : ne pas mettre le path en dur

LFLAGS		=
LFLAGS		+=	-L ./../libraries/libmy -l my
LFLAGS		+=	-L ./../libraries/libzappy -l zappy
LFLAGS		+=	-L ./../libraries/liblist -l list
LFLAGS		+=	-L ./../libraries/libsocket -l socket
LFLAGS		+=	-l Irrlicht

all		:	$(NAME)

$(NAME)		:	$(OBJECTS)
			$(CXX) -o $(NAME) $(OBJECTS) $(LFLAGS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean	all
