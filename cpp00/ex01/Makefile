
NAME		= phonebook
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	=	src/main.cpp \
			src/Contact.cpp \
			src/PhoneBook.cpp \
			src/input.cpp \
			src/checker.cpp \
			src/executer.cpp \
			src/renderer.cpp \
			src/validations.cpp \
			src/utils.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
