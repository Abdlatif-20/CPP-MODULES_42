# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 16:51:24 by aben-nei          #+#    #+#              #
#    Updated: 2023/10/09 17:31:38 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS = Contact.cpp PhoneBook.cpp

CPP = c++

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo -e "\033[32mPhonebook is ready to use !\033[0m"

%.o: %.cpp %.hpp
	@$(CPP) $(FLAGS) -c $< -o $@
	@echo -e "\033[33mCompiling $<\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[31mObject files deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo -e "\033[31mPhonebook deleted\033[0m"

re: fclean all
