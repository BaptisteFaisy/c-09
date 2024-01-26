NAME = PmergeMe
CC = c++
FLAGS = -Wall -Wextra -Werror -g3
SRCS = main.cpp PmergeMe.cpp
# SRCS = $(addprefix $(DIR)/,$(SRCS_RAW))
OBJS = $(SRCS:c=o)
# DIR = srcs

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean :
	rm -rf $(NAME)
re: clean all