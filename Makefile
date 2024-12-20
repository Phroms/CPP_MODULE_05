# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrimald <agrimald@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 11:27:47 by agrimald          #+#    #+#              #
#    Updated: 2024/12/20 16:19:29 by agrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf
CYAN = \033[96m
RED = \033[91m
YELLOW = \033[93m
END_COLOR = \033[0m

SRC = main.cpp Bureaucrat.cpp

INC = Bureaucrat.hpp

OBJECTS = $(SRC:.cpp=.o)

all: banner $(NAME)

banner: 
		@printf "\n"

$(NAME): $(OBJECTS)
		@printf "$(CYAN)\nCompiling!!!\n$(END_COLOR)\n"
		@$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp $(INC) Makefile
		@printf "$(YELLOW)Generating objects... %s $(END_COLOR)\r" $@
		@$(CPP) $(CPPFLAGS) -c $< -o $@

fclean: clean
		$(RM) $(NAME) $(OBJECTS)

clean:
		@printf "$(RED)\nRemoving!!!\n$(END_COLOR)\n"
		@$(RM) $(OBJECTS)

re: fclean all

.PHONY: re clean fclean all
