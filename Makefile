# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 14:25:55 by mkarim            #+#    #+#              #
#    Updated: 2023/01/04 13:11:11 by mkarim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES_MAIN = includes/vector.hpp 

UTILS_INC = utils/enable_if.hpp utils/is_integral.hpp

INCLUDES = $(INCLUDES_MAIN) $(UTILS_INC);

SRC = main.cpp $(UTILS_FILES)

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
