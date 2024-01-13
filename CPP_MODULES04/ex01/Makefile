# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 14:34:22 by aben-nei          #+#    #+#              #
#    Updated: 2024/01/13 10:28:47 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = Animal

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.cpp)

INC = $(wildcard *.hpp)

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(Name)
	@echo "\033[32m[OK] \033[0m\033[1mCompilation \033[0m\033[36m$(Name)\033[0m"

%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "\033[32m[OK] \033[0m\033[1mCompilation $@\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[OK] \033[0m\033[1mDelete $(OBJ)\033[0m"

fclean: clean
	@rm -rf $(Name)
	@echo "\033[31m[OK] \033[0m\033[1mDelete $(Name)\033[0m"

re: fclean all