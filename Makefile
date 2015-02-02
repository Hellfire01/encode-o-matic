##
## Makefile for norme in /home/raynau_a/test-zone/window_test
## 
## Made by a
## Login   <raynau_a@epitech.net>
## 
## Started on  Wed Dec  4 14:06:06 2013 a
## Last update Thu Aug 14 22:00:56 2014 mat
## Last update Fri Feb 14 00:26:09 2014 a
##


NAME	= 	encode-o-matic

SRCS	=	sources/main.cpp	\
		sources/user_input.cpp	\
		sources/cesars.cpp	\
		sources/vigenere.cpp	\
		sources/lib.cpp		\
		sources/isin.cpp

OBJS	= 	$(SRCS:.cpp=.o)

CPPFLAGS	+= 	-Wall -Wextra -g3
CPPFLAGS	+=	-I ./includes

all	:	$(NAME)

$(NAME)	:	$(OBJS) $(LOBJS)
		g++ -o $(NAME) $(OBJS) $(LOBJS)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

## à partir d'ici ce ne sont que des commandes aditionnelles

go	:
		clear
		./$(NAME)

gov	:
		clear
		valgrind -v -q ./$(NAME)

govplus	:
		clear
		valgrind -v -q --leak-check=full ./$(NAME)

exe	:	abs
		@echo -e '\033[0;32m execution de :\n=== \033[0;36m'$(NAME)'\033[0;32m === \033[0m'
		./$(NAME)

val	:	abs
		@echo -e '\033[0;32m execution de :\n=== \033[0;36m'$(NAME)'\033[0;32m === \033[0m'
		valgrind -v -q ./$(NAME)

abs	:	abs_0 $(NAME)
		@echo -e '\033[0;32m (2/2) >> la compilation a réussie\033[0m'
		@echo -e '' 
		ls -a --color
		@echo -e ''

abs_0	:
		clear
		@echo -e '\033[0;32m (1/2) >> compilation de \033[0;35m"'$(NAME)'"\033[0m'

.PHONY	:	all abs abs_0 clean clear exe fclean go gov govplus re val
