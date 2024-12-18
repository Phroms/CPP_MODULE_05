# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrimald <agrimald@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 11:27:47 by agrimald          #+#    #+#              #
#    Updated: 2024/12/18 12:00:22 by agrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf
CYAN = \033[96m
RED = \033[91m
END_COLOR = \033[0m

SRC = main.cpp

INC = prueba.hpp

OBJECTS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@echo "$(CYAN)\nCompiling!!!\n$(END_COLOR)"
		$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp $(INC) Makefile
		$(CPP) $(CPPFLAGS) -c $< -o $@

fclean: clean
		$(RM) $(NAME) $(OBJECTS)

clean:
		@echo "$(RED)\nRemoving!!!\n$(END_COLOR)"
		$(RM) $(OBJECTS)

re: clean fclean all

.PHONY: re clean fclean all
