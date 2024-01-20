# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 18:48:44 by aben-nei          #+#    #+#              #
#    Updated: 2024/01/20 21:41:23 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name =  array

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)

INC = $(wildcard *.hpp)

INCT = $(wildcard *.tpp)

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(Name)
	@echo "\033[32m[OK] \033[0m\033[1mCompilation \033[0m\033[35m$(Name)\033[0m"

%.o: %.cpp $(INC) $(INCT)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "\033[32m[OK] \033[0m\033[1mCompilation $@\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[OK] \033[0m\033[1mDelete $(OBJ)\033[0m"

fclean: clean
	@rm -rf $(Name)
	@echo "\033[31m[OK] \033[0m\033[1mDelete $(Name)\033[0m"

re: fclean all