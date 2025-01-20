# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrimald <agrimald@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 17:51:03 by agrimald          #+#    #+#              #
#    Updated: 2025/01/20 16:01:12 by agrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Shrubbery
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf
CYAN = \033[96m
RED = \033[91m
YELLOW = \033[93m
END_COLOR = \033[0m

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForms.cpp

INC = AForm.hpp Bureaucrat.hpp SHrubberyCreationForm.hpp \
	  	RobotomyRequestForm.hpp PresidentialPardonForms.hpp

OBJECTS = $(SRC:.cpp=.o)

all: banner $(NAME)

banner:
		 @printf "\n"

$(NAME): $(OBJECTS)
		 @printf "$(CYAN)\nCompiling!\n$(END_COLOR)\n"
		 @$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp $(INC) Makefile
		 @printf "$(YELLOW)Generating objects... %s $(END_COLOR)\r" $@
		 @$(CPP) $(CPPFLAGS) -c $< -o $@

fclean: clean
		$(RM) $(NAME) $(OBJECTS)

clean:
		 @printf "$(RED)\nRemoving!\n$(END_COLOR)\n"
		 @$(RM) $(OBJECTS)

re: fclean all

.PHONY: re clean fclean all
