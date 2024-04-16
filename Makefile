##
## EPITECH PROJECT, 2024
## Raytracer
## File description:
## Makefile of the project
##

NAME = raytracer
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror
INCLUDES_DIR = includes
SRC_DIR = src

SRC =       src/Main.cpp \
			src/models/Vector3D.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
