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

SRCS	=	sources/fichiers/main.cpp						\
		sources/fichiers/info.cpp						\
		sources/fichiers/chiffrement/cesars.cpp				\
		sources/fichiers/chiffrement/102/102.cpp				\
		sources/fichiers/chiffrement/102/102_matrix_input.cpp		\
		sources/fichiers/chiffrement/102/102_utilitaires.cpp		\
		sources/fichiers/chiffrement/v102.cpp				\
		sources/fichiers/chiffrement/vigenere.cpp				\
		sources/fichiers/utilitaires/lib.cpp				\
		sources/fichiers/utilitaires/isin.cpp				\
		sources/fichiers/utilitaires/user_input.cpp			\
		sources/fichiers/utilitaires/epur_str.cpp				\
		sources/fichiers/utilitaires/epur_string.cpp			\
		sources/fichiers/utilitaires/color_str.cpp			\
		sources/fichiers/maths/bases.cpp					\
		sources/fichiers/maths/bases_string.cpp				\
		sources/fichiers/maths/matrix.cpp

OBJS	= 	$(SRCS:.cpp=.o)

CPPFLAGS	+=	-Wall -Wextra -g3
CPPFLAGS	+=	-I ./sources/includes
CPPFLAGS	+=	-I ./sources/librairies/eigen

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		g++ -o $(NAME) $(OBJS)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

test	:	re clean

.PHONY	:	all clean fclean re test
