##
## Makefile for world in /home/marie/zappy/zappy/project/world
## 
## Made by lefebv_z
## Login   <marie@epitech.net>
## 
## Started on  Mon Jun 30 12:30:44 2014 lefebv_z
## Last update Mon Jul  7 19:41:36 2014 lefebv_z
##

CXX		?=	clang++

NAME		=	world

SOURCES		=	$(shell find ./sources -name "*.cpp")

OBJECTS		=	$(SOURCES:.cpp=.o)

CXXFLAGS		=	-ansi -pedantic -g 
CXXFLAGS		+=	-Wall -Wextra
CXXFLAGS		+=	-std=c++11
CXXFLAGS		+=	-I ./interfaces
CXXFLAGS		+=	-I ./sources
CXXFLAGS		+=	-I ./sources/engine
CXXFLAGS		+=	-I ./sources/singletons
CXXFLAGS		+=	-I ./sources/map
CXXFLAGS		+=	-I ./sources/gui
CXXFLAGS		+=	-I ./sources/object
CXXFLAGS		+=	-I ./sources/wrappers
CXXFLAGS		+=	-I ./sources/network
CXXFLAGS		+=	-I ./../libraries/libmy/headers
CXXFLAGS		+=	-I ./../libraries/liblist/headers
CXXFLAGS		+=	-I ./../libraries/libsocket/headers
CXXFLAGS		+=	-I ./../libraries/libzappy/headers
CXXFLAGS		+=	$(shell pkg-config --cflags glib-2.0) $(shell pkg-config --cflags openssl)
CXXFLAGS		+=	-isystem /usr/include/irrlicht #TODO : ne pas mettre le path en dur

LFLAGS		=
LFLAGS		+=	-L ./../libraries/libzappy -l zappy
LFLAGS		+=	-L ./../libraries/liblist -l list
LFLAGS		+=	-L ./../libraries/libsocket -l socket
LFLAGS		+=	-L ./../libraries/libmy -l my
LFLAGS		+=	-l Irrlicht
LFLAGS		+=	-l pthread
LFLAGS		+=	$(shell pkg-config --libs openssl)

all		:	$(NAME)

$(NAME)		:	$(OBJECTS)
			$(CXX) -o $(NAME) $(OBJECTS) $(LFLAGS)

clean		:
			rm -f $(OBJECTS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean	all
