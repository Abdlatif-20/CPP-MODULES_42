# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 02:45:36 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/31 23:36:08 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixedPoint

SRCS = Fixed.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32m[OK] \033[0m\033[1m\033[32m$(NAME)\033[0m \033[1mcreated\033[0m"

%.o: %.cpp Fixed.hpp
	@$(CPP) $(FLAGS) -c $< -o $@
	@echo "\033[32m[OK] \033[0m\033[1mCompilation of \033[36m$<\033[0m \033[1msuccessfull\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "\033[31m[OK] \033[0m\033[1mObjects files deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m[OK] \033[0m\033[1m$(NAME) deleted\033[0m"

re: fclean all
