# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 11:02:45 by aben-nei          #+#    #+#              #
#    Updated: 2024/01/04 22:49:08 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = ClapTrap

SRC = main.cpp ClapTrap.cpp

OBJ = $(SRC:.cpp=.o)

CPP = c++

Flags = -Wall -Wextra -Werror -std=c++98

all: $(Name)

$(Name): $(OBJ)
	@$(CPP) $(Flags) $(OBJ) -o $(Name)
	@echo "\033[32m[ClapTrap] Created\033[0m"

%.o: %.cpp ClapTrap.hpp
	@$(CPP) $(Flags) -c $< -o $@
	@echo "\033[33m[ClapTrap] Compiling $<\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[ClapTrap] Cleaned\033[0m"

fclean: clean
	@rm -rf $(Name)
	@echo "\033[31m[ClapTrap] Deleted\033[0m"

re: fclean all