# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <rmocsai@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 09:10:51 by rmocsai           #+#    #+#              #
#    Updated: 2023/07/12 10:43:42 by rmocsai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colors
CLR_RM 		= \033[0m
BOLD 		= \033[1m
MAGENTA		= \033[0;95m
CYAN 		= \033[1;36m
RED		    = \033[1;31m
YELLOW		= \033[1;33m
#BLACK 		= \033[30m
#BLUE		= \033[1;34m
#GREEN		= \033[1;32m
#WHITE		= \033[0;97m

# target
NAME 		= philo

# directories
SRC_DIR 	= ./src/
INC_DIR 	= ./inc/
OBJ_DIR 	= ./obj/
DEP_DIR		= $(OBJ_DIR)dep

# compilation
CC 			= cc
CPPFLAGS 	= -I $(INC_DIR)
DEPFLAGS	= #-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
CFLAGS 		= -Wall -Werror -Wextra -pthread -g
COMPILE 	= $(CC) $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS)

# source files
SRC 		=	main.c \
				checker.c \
				init.c \
				utils.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC))

# objects
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ))

# dependencies
#DEPFILES :=$(SRC:%.c=$(DEP_DIR)/%.d)

.PHONY: all re clean fclean 
.SILENT:

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
		mkdir -p obj
		$(COMPILE) -c $< -o $@

# $(DEP_DIR):
# 	printf "\n$(YELLOW)$(BOLD)create subdir$(CLR_RM) [$(CYAN)philosophers$(CLR_RM)]\n"
# 	mkdir -p $@
#$(DEPFILES):

all: $(NAME)

$(NAME): $(OBJS)
	echo "Compilation in progress..."
	$(COMPILE) $(OBJS) -o $@
	echo "$(CYAN)$(BOLD)$(NAME) $(CLR_RM)created ✔️"


clean:
	rm -rf $(OBJ_DIR)
	echo "$(RED)Deleting$(CLR_RM) object files ✔️"

fclean: clean
	rm -rf $(NAME)
	echo "$(RED)Deleting$(CLR_RM) binary: $(CYAN)$(NAME)$(CLR_RM) ✔️"

re: fclean all

debug: CFLAGS += -fsanitize=address
debug: fclean $(NAME)
	echo "DEBUG: Compiled with $(MAGENTA)$(BOLD)fsanitize=address$(CLR_RM)"

tebug: CFLAGS += -fsanitize=thread
tebug: fclean $(NAME)
	echo "DEBUG: Compiled with $(MAGENTA)$(BOLD)fsanitize=thread$(CLR_RM)"