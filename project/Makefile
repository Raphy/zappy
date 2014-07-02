##
## Makefile for zappy in /home/raphy/Epitech/Tech_2/zappy/project
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Mon May 12 13:17:39 2014 raphael defreitas
## Last update Wed Jul  2 16:13:43 2014 raphael defreitas
##

LIBS_PATH	=	./libraries/
LIBS		=	libmy liblist libsocket libzappy

DIRECTORIES	=	./server ./remote ./world

all		:	reminder norm zappy

reminder	:
			@echo "Ne pas oublier de remplacer les variables SOURCES des Makefile (au lieu des wildcards) avant de faire le rendu final !"
			@sleep 3

norm		:
			@echo "Checking basic norm..."
			@find -name "*.c" -exec ../tools/norme.py {} \;
			@find -name "*.h" -exec ../tools/norme.py {} \;

libs		:
			make -C $(LIBS_PATH)
			$(foreach lib, $(LIBS), make -C $(LIBS_PATH)/$(lib);)

zappy		:	libs
			$(foreach dir, $(DIRECTORIES), make -C $(dir);)

clean		:
			$(foreach lib, $(LIBS), make fclean -C $(LIBS_PATH)/$(lib);)
			$(foreach dir, $(DIRECTORIES), make clean -C $(dir);)

fclean		:
			make fclean -C $(LIBS_PATH)
			$(foreach lib, $(LIBS), make fclean -C $(LIBS_PATH)/$(lib);)
			$(foreach dir, $(DIRECTORIES), make fclean -C $(dir);)

re		:	fclean zappy
