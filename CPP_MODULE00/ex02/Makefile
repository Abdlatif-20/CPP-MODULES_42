# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 20:41:25 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/08 15:12:38 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32mAccount is ready to use !\033[0m"

%.o: %.cpp Account.hpp
	@$(CPP) $(FLAGS) -c $< -o $@
	@echo "\033[33mCompiling $<\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "\033[31mObject files deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mPhonebook deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re