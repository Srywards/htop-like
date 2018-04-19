##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CXX	=	g++

RM	=	rm -f

CXXFLAGS	=	-I./includes/
CXXFLAGS	+=	-I./includes/info_sys
CXXFLAGS	+=	-I./includes/ncurses
CXXFLAGS	+=	-I./includes/sfml
CXXFLAGS	+=	-W -Wall -Wextra -Werror
CXXFLAGS	+=	-std=gnu++11 -lncurses

SRC	=	srcs/ncurses/Ncurses.cpp 	\
		srcs/info_sys/InfoName.cpp	\
		srcs/info_sys/InfoKernel.cpp	\
		srcs/info_sys/InfoTime.cpp	\
		srcs/info_sys/InfoRam.cpp	\
		srcs/info_sys/monitor_core.cpp	\
		srcs/info_sys/InfoCpu.cpp	\
		srcs/info_sys/InfoNetwork.cpp	\
		srcs/sfml/Sfml.cpp

SRCMAIN	=	srcs/main.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJM	+=	$(SRCMAIN:.cpp=.o)

NAME	=	my_gkrellm

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(OBJM)
		$(CXX) $(OBJM) $(OBJ) -o $(NAME) $(CXXFLAGS) -lsfml-graphics -lsfml-window -l\
		sfml-system

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
