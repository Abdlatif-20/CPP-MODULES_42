# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 02:13:50 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/08 22:40:06 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = weapon

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

OBJ = $(SRC:.cpp=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(Name)

%.o: %.cpp %.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re