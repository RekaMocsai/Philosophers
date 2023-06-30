# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <rmocsai@student.42.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 09:10:51 by rmocsai           #+#    #+#              #
#    Updated: 2023/06/30 16:17:43 by rmocsai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# targets
NAME 		= philo

# colors
CLR_RM 		= \033[0m
BOLD 		= \033[1m
BLACK 		= \033[30m
MAGENTA		= \033[0;95m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED		    = \033[1;31m
WHITE		= \033[0;97m

# directories
SRC_DIR 	= src
INC_DIR 	= inc
OBJ_DIR 	= obj
DEP_DIR 	= $(OBJ_DIR)/dep

# compilation
CC 			= cc
CPPFLAGS 	= -I $(INC_DIR)
CFLAGS 		= -Wall -Werror -Wextra -pthread -g
DEPFLAGS 	= -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
COMPILE 	= $(CC) $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS)

# source files
SRC 		= i

PHONY. all re clean fclean
SILENT.

all: $(NAME)

$(NAME): $(OBJS)
	echo "Compilation in progress..."
	$(COMPILE) $(OBJS) -o $@
	echo "$(CYAN)$(BOLD)$(NAME) $(CLR_RM)created ✔️"
	
clean:
	rm -rf $(OBJ_DIR)
	echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RM)object files ✔️"

fclean: clean
	rm -rf $(NAME)
	echo "$(RED) binary removed $(NAME)$(CLR_RM)"

re: fclean all

debug: CFLAGS += -fsanitize=address
debug: fclean $(NAME)
	echo "DEBUG: Compiled with $(MAGENTA)$(BOLD)fsanitize=address$(CLR_RM)"

tebug: CFLAGS += -fsanitize=thread
tebug: fclean $(NAME)
	echo "DEBUG: Compiled with $(MAGENTA)$(BOLD)fsanitize=thread$(CLR_RM)"