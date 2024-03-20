# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 04:28:06 by aben-nei          #+#    #+#              #
#    Updated: 2024/03/19 21:53:36 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)

INC = $(wildcard *.hpp)

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32m[OK] \033[0m\033[1mCompilation \033[0m\033[35m$(NAME)\033[0m"

%.o: %.cpp $(INC)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "\033[32m[OK] \033[0m\033[1mCompilation $@\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[OK] \033[0m\033[1mDelete $(OBJ)\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m[OK] \033[0m\033[1mDelete $(NAME)\033[0m"

re: fclean all