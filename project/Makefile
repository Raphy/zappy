##
## Makefile for zappy in /home/raphy/Epitech/Tech_2/zappy/project
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Mon May 12 13:17:39 2014 raphael defreitas
## Last update Mon May 12 13:42:24 2014 raphael defreitas
##

LIBS_PATH	=	./libraries/
LIBS		=	liblist libsocket libzappy

all		:	norm libs

norm		:
			@echo -e "\e[1;31mChecking basic norm...\e[0;31m"
			@find -name "*.c" -exec ../tools/norme.py {} \;
			@find -name "*.h" -exec ../tools/norme.py {} \;
			@echo -en "\e[0m"


libs		:
			@echo -e "\e[1;35mCompiling the libraries...\e[0;35m"
			$(foreach lib, $(LIBS), make -C $(LIBS_PATH)/$(lib);)
			@echo -en "\e[0m"

clean		:

fclean		:
