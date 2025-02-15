
NAME		= main
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -DDEBUG_MODE=1

SRCS	= main.cpp debug.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
