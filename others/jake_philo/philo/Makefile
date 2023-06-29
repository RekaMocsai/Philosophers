NAME = philo
SRC = create_mutex.c create_threads.c eat_sleep_think.c error_free.c get_argv_infos.c get_time.c main.c \
		philos_check.c print_msg.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAG = -Wall -Werror -Wextra
OPTION = -o

all: $(NAME)

$(NAME):
		$(CC) $(OPTION) $(NAME) $(FLAG) $(SRC) -pthread

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

bonus:	all

.PHONY: all bonus clean fclean re
