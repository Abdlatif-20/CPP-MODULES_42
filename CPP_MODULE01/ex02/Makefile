# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 01:45:53 by aben-nei          #+#    #+#              #
#    Updated: 2023/10/18 01:46:54 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = program

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++

FLAGS = -Wall -Wextra -Werror

all: $(Name)

$(Name): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(Name)


%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(Name)

re: fclean all