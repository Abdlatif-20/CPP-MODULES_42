# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 17:10:55 by aben-nei          #+#    #+#              #
#    Updated: 2024/01/20 17:26:08 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


Name =  whatever

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(wildcard *.cpp)

INC = $(wildcard *.hpp)

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(Name)
	@echo "\033[32m[OK] \033[0m\033[1mCompilation \033[0m\033[35m$(Name)\033[0m"

%.o: %.cpp $(INC)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "\033[32m[OK] \033[0m\033[1mCompilation $@\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[31m[OK] \033[0m\033[1mDelete $(OBJ)\033[0m"

fclean: clean
	@rm -rf $(Name)
	@echo "\033[31m[OK] \033[0m\033[1mDelete $(Name)\033[0m"

re: fclean all