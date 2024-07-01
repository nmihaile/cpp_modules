
NAME	= phonebook
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= src/main.cpp src/contact.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
