# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 14:25:55 by mkarim            #+#    #+#              #
#    Updated: 2022/12/08 18:39:03 by mkarim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = includes/vector.hpp

SRC_PATH = ./srcs

UTILS_PATH = ./utils

SRC_FILES = $(SRC_PATH)/vector.cpp

UTILS_FILES = $(UTILS_PATH)/vector_utils.cpp

SRC = main.cpp $(SRC_FILES) $(UTILS_FILES)

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
