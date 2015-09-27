SRCS	=	main.cpp					\
		core/Choice.cpp					\
		core/Brick.cpp					\
		core/Constructor/Constructor.cpp		\
		core/Constructor/Constructor_lib.cpp		\
		core/Constructor/Constructor_status.cpp		\
		core/bricks/Cesars.cpp				\
		core/bricks/Vigenere.cpp			\
		core/bricks/102/_102_input.cpp			\
		core/bricks/102/_102_key_input.cpp		\
		core/bricks/102/_102_chiffre_dechiffre.cpp	\
		core/bricks/102/_102_brick_functions.cpp	\
		core/bricks/102/_102_matrix_input.cpp		\
		core/bricks/102/_102_utilitaires.cpp		\
		core/utilitaires/lib.cpp			\
		core/utilitaires/lib_check.cpp			\
		core/utilitaires/isin.cpp			\
		core/utilitaires/user_input.cpp			\
		core/utilitaires/epur_str.cpp			\
		core/utilitaires/color_str.cpp			\
		core/maths/bases.cpp				\
		core/maths/bases_string.cpp			\
		core/maths/matrix.cpp				\
		term/main_term.cpp				\
		term/info.cpp					\
		term/chiffrement/cesars.cpp			\
		term/chiffrement/102_functions.cpp		\
		term/chiffrement/vigenere.cpp			\
		term/chiffrement/v102.cpp			\
		instant/main_instant.cpp			\
		graph/qt5/main_qt5.cpp				\
		graph/sdl/main_sdl.cpp

NAME	= encode-o-matic

define my_color
	@tput setaf $2
	@tput bold
	@echo $1
	@tput sgr0
endef

CXX	= @clang++
RM	= @rm -frv
MK	= @mkdir -p

SRCDIR	= sources/sources
OBJDIR	= .obj
INCDIR	= ./sources/includes

CFLAGS	+= -Wall -Wextra
CFLAGS	+= -pedantic
CFLAGS  += -std=c++11
CFLAGS	+= -I $(INCDIR)/core
CFLAGS	+= -I $(INCDIR)/fichiers
CFLAGS	+= -I $(INCDIR)/term
CFLAGS	+= -I $(INCDIR)/instant
CFLAGS	+= -I $(INCDIR)/graph
CFLAGS	+= -I ./librairies/eigen
#décommenter pour debug
#CFLAGS  += -g3

OBJS	=	$(SRCS:%.cpp=$(OBJDIR)/%.o)

all	: 	info $(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
	$(MK) $(addprefix $(OBJDIR)/, $(SRCS))
	@echo -e "\033[1;32mCompiling $< \033[0;0m"
	$(CXX) -o $@ -c $< $(CFLAGS)

$(NAME)	:	$(OBJS)
	$(call my_color, "Linking $(NAME) ...", 3)
	$(CXX)  -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
	$(call my_color, "Cleaning object files ...", 4)
	$(RM) $(OBJS)

fclean	:	clean
	$(call my_color, "Cleaning binaries ...", 4)
	$(RM) $(NAME)

sclean	:
	$(call my_color, "deleting obj folder ...", 4)
	$(RM) .obj

info	:
	@echo -e "\033[1;35mCompiling" $(NAME) "...\033[0;0m"
	@echo -e "\033[1;31mFlags are :\033[1;36m" $(CFLAGS) "\033[0;0m"


re	:	fclean all

test	:	fclean all clean

.PHONY: all clean fclean sclean info re test
