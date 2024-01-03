# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 01:28:41 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/23 19:04:29 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = zombiehorde

Flags = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = Zombie.cpp zombieHorde.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	@$(CPP) $(Flags) $(OBJ) -o $(Name)
	@echo "\033[32m[ ✔ ] $(Name) created successfully!\033[0m"

%.o: %.cpp Zombie.hpp
	@$(CPP) $(Flags) -c $< -o $@
	@echo "\033[33m[ ✔ ] $<\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[ ✔ ] $(Name) objects deleted successfully!\033[0m"

fclean: clean
	@rm -rf $(Name)
	@echo "\033[31m[ ✔ ] $(Name) deleted successfully!\033[0m"

re: fclean all

.PHONY: all clean fclean re