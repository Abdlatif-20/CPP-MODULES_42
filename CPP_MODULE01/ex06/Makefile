# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 19:18:36 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/23 19:15:41 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

SRCS = main.cpp \
		Harl.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32m[ ✔ ] $(NAME) created successfully!\033[0m"

%.o: %.cpp Harl.hpp
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[33m[ ✔ ] $<\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "\033[31m[ ✔ ] $(NAME) objects deleted successfully!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m[ ✔ ] $(NAME) deleted successfully!\033[0m"

re: fclean all

.PHONY: all clean fclean re