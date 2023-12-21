# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 12:41:12 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/08 23:00:31 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed

SRCS = main.cpp Getfile.cpp Openfile.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

CPLUS = c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CPLUS) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Getfile.hpp
	$(CPLUS) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re