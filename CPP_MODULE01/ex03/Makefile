# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 02:13:50 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/23 19:12:40 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = weapon

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

flags = -Wall -Wextra -Werror -std=c++98

CPP = c++

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	@$(CPP) $(flags) $(OBJ) -o $(Name)
	@echo "\033[32m[ ✔ ] $(Name) created successfully!\033[0m"

%.o: %.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	@$(CPP) $(flags) -c $< -o $@
	@echo "\033[33m[ ✔ ] $<\033[0m"


clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[ ✔ ] $(Name) objects deleted successfully!\033[0m"

fclean: clean
	@rm -rf $(Name)
	@echo "\033[31m[ ✔ ] $(Name) deleted successfully!\033[0m"

re: fclean all

.PHONY: all clean fclean re