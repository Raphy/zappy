##
## Makefile for zappy in /home/raphy/Epitech/Tech_2/zappy/project
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Mon May 12 13:17:39 2014 raphael defreitas
## Last update Mon May 12 14:06:10 2014 raphael defreitas
##

LIBS_PATH	=	./libraries/
LIBS		=	liblist libsocket libzappy

DIRECTORIES	=	./server

all		:	reminder norm libs project

reminder	:
			@echo -e "\e[1;31mNe pas oublier de remplacer les variables SOURCES des Makefile (au lieu des wildcards) avant de faire le rendu final !\e[0m"
			@sleep 1

norm		:
			@echo -e "\e[1;31mChecking basic norm...\e[0;31m"
			@find -name "*.c" -exec ../tools/norme.py {} \;
			@find -name "*.h" -exec ../tools/norme.py {} \;
			@echo -en "\e[0m"

libs		:
			@echo -e "\e[1;35mCompiling the libraries...\e[0;35m"
			$(foreach lib, $(LIBS), make -C $(LIBS_PATH)/$(lib);)
			@echo -en "\e[0m"

project		:	libs
			$(foreach dir, $(DIRECTORIES), make -C $(dir);)

clean		:
			$(foreach dir, $(DIRECTORIES), make clean -C $(dir);)

fclean		:
			$(foreach dir, $(DIRECTORIES), make fclean -C $(dir);)

re		:	fclean project
