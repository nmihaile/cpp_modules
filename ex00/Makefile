
NAME		=	main
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror

SRCS		=	main.cpp tester.cpp
OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

t: $(NAME)
	@./$(NAME) t

re: fclean all
