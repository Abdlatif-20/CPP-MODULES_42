# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 00:57:48 by aben-nei          #+#    #+#              #
#    Updated: 2023/10/18 01:15:04 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = zombie

Flags = -Wall -Wextra -Werror

CPP = c++

SRC = Zombie.cpp newZombie.cpp main.cpp randomChump.cpp

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