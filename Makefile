# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmocsai <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 09:10:51 by rmocsai           #+#    #+#              #
#    Updated: 2023/06/29 09:14:37 by rmocsai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# targets
NAME := philo

# colors
RESET := \033[0m
BOLD := \033[1m
BLACK := \033[30m
GREEN := \033[32m
YELLOW := \033[33m
RED := \033[31m
BLUE := \033[34m

# directories
SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
DEP_DIR := $(OBJ_DIR)/dep

# compilation
CC := cc
CPPFLAGS = -I $(INC_DIR)
CFLAGS = -Wall -Werror -Wextra -pthread -g
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
COMPILE = $(CC) $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS)

# source files
SRC :=i

PHONY. all re clean fclean
SILENT.

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	$(COMPILE) $(OBJS) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation succesful$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	@printf "$(GREEN)$(BOLD)$(NAME)$(RESET) created!$(RESET)\n\n"
iclean:
	@printf "\n$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)philosophers$(RESET)]\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)removed subdir $(OBJ_DIR)$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED)removed binary $(NAME)$(RESET)\n"

re: fclean alli

debug: CFLAGS += -fsanitize=address
debug: fclean $(NAME)
	@printf "DEBUG: Compiled with $(YELLOW)$(BOLD)fsanitize=address$(RESET)\n\n"

tebug: CFLAGS += -fsanitize=thread
tebug: fclean $(NAME)
	@printf "DEBUG: Compiled with $(YELLOW)$(BOLD)fsanitize=thread$(RESET)\n\n"

