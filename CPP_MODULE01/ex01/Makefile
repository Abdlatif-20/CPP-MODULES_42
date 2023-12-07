# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 01:28:41 by aben-nei          #+#    #+#              #
#    Updated: 2023/10/18 01:30:30 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = zombiehorde

Flags = -Wall -Wextra -Werror

CPP = c++

SRC = Zombie.cpp zombieHorde.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CPP) $(Flags) $(OBJ) -o $(Name)

%.o: %.cpp %.hpp
	$(CPP) $(Flags) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re