# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 01:45:53 by aben-nei          #+#    #+#              #
#    Updated: 2023/12/23 19:05:11 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = program

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(Name)

$(Name): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $(Name)
	@echo "\033[32m[ ✔ ] $(Name) created successfully!\033[0m"


%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@
	@echo "\033[33m[ ✔ ] $<\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "\033[31m[ ✔ ] $(Name) objects deleted successfully!\033[0m"

fclean: clean
	@rm -rf $(Name)
	@echo "\033[31m[ ✔ ] $(Name) deleted successfully!\033[0m"

re: fclean all