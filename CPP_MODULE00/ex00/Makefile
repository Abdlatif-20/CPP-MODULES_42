# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 16:16:36 by aben-nei          #+#    #+#              #
#    Updated: 2023/10/09 16:27:59 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CPP = c++

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo -e "\033[32mCreated $(NAME) successfully!\033[0m"

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@
	@echo -e "\033[33mCompiling $<\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[31mRemoved $(OBJS) successfully!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo -e "\033[31mRemoved $(NAME) successfully!\033[0m"

re: fclean all

.PHONY: all clean fclean re