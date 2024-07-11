
NAME		= ftrplc
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp ft_replace.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

###################### TESTS ######################

SHELL := /bin/bash
LR = "\033[0;91m"
LG = "\033[0;92m"
LC = "\033[0;96m"
DG = "\033[0330;90m"
R  = "\033[0m"

define NEWLINE_VAR
hello
world
endef

export NEWLINE_VAR

test:
	@if [ ! -e "ftrplc" ]; then \
		echo -e $(LR)"File 'ftrplc' does not exist. Create it first to run the tests…"$(R); \
		exit 1; \
	fi

	@echo
	@echo -e $(DG)"Shell version: $$($(SHELL) --version)"
	@echo -e "--------------------------------------------------------------------------"$(R)
	@echo

	@echo -e '[TEST 01] › Tests wrong nbr of arguments '$(LC)'./ftrplc'$(R)
	@echo -n '          › '
	@res=$$(./$(NAME) tests/test 2>&1); \
	expected='ftrplc: Wrong number of arguemnts usage: ./ftrplc <filename> <string1> <string2>'; \
	diff <(echo $$res) <(echo $$expected) >/dev/null \
		&& echo -e $(LG)"[OK]"$(R) \
		|| echo -e $(LR)"[KO]"$(R); true;

	@echo -e '[TEST 02] › Tests normal behavior '$(LC)'./ftrplc tests/test01 hallo HALLO'$(R)
	@echo -n '          › '
	@./$(NAME) tests/test hello HELLO
	@(diff tests/test.replace tests/test02.expected > /dev/null && echo -e $(LG)"[OK]"$(R)) || echo -e $(LR)"          › [KO]"$(R)

	@echo -e '[TEST 03] › Tests empty s1 '$(LC)'./ftrplc tests/test01 "" HALLO'$(R)
	@echo -n '          › '
	@res=$$(./$(NAME) tests/test '' HELLO 2>&1); \
	diff <(echo $$res) <(echo "Error: string1: is empty.") >/dev/null \
		&& echo -e $(LG)"[OK]"$(R) \
		|| echo -e $(LR)"[KO]"$(R); true;

	@echo -e '[TEST 04] › Tests open none_existing in_file '$(LC)'./ftrplc none_existing hello HALLO'$(R)
	@echo -n '          › '
	@res=$$(./$(NAME) none_existing hello HELLO 2>&1); \
	diff <(echo $$res) <(echo "Error: failed to open: none_existing") >/dev/null \
		&& echo -e $(LG)"[OK]"$(R) \
		|| echo -e $(LR)"[KO]"$(R); true;

	@echo -e '[TEST 05] › Tests failing out_file '$(LC)'./ftrplc tests/test02 hello HALLO'$(R)
	@echo -n '          › '
	@res=$$(./$(NAME) tests/test05 hello HELLO 2>&1); \
	diff <(echo $$res) <(echo "Error: failed to open: tests/test05.replace") >/dev/null \
		&& echo -e $(LG)"[OK]"$(R) \
		|| echo -e $(LR)"[KO]"$(R); true;

	@echo -e '[TEST 06] › Tests s1 string with newline character '$(LC)'./ftrplc tests/test01 "hello\\nworld" "HELLO WORLD"'$(R)
	@echo -n '          › '
	@./$(NAME) tests/test "$$NEWLINE_VAR" "HELLO WORLD"
	@(diff tests/test.replace tests/test06.expected > /dev/null && echo -e $(LG)"[OK]"$(R)) || echo -e $(LR)"          › [KO]"$(R)

	@echo -e '[TEST 07] › Tests replacing with same value '$(LC)'./ftrplc tests/test hello hello'$(R)
	@echo -n '          › '
	@./$(NAME) tests/test hello hello
	@(diff tests/test tests/test.replace > /dev/null && echo -e $(LG)"[OK]"$(R)) || echo -e $(LR)"          › [KO]"$(R)
