# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 12:41:12 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/23 19:13:35 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed

SRCS = main.cpp Getfile.cpp Openfile.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

CPLUS = c++

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPLUS) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32m[ ✔ ] $(NAME) created successfully!\033[0m"

%.o: %.cpp Getfile.hpp
	@$(CPLUS) $(FLAGS) -c $< -o $@
	@echo "\033[33m[ ✔ ] $<\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "\033[31m[ ✔ ] $(NAME) objects deleted successfully!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m[ ✔ ] $(NAME) deleted successfully!\033[0m"

re: fclean all

.PHONY: all clean fclean re