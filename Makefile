# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 14:25:55 by mkarim            #+#    #+#              #
#    Updated: 2022/12/21 16:45:19 by mkarim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = includes/vector.hpp

# UTILS_PATH = ./utils

# UTILS_FILES = $(UTILS_PATH)/vector_utils.cpp

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
