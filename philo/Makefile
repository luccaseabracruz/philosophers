# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 16:37:00 by lseabra-          #+#    #+#              #
#    Updated: 2026/03/10 15:10:21 by lseabra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                 COLOR CODES                                  #
#==============================================================================#
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
RESET	= \033[0m

#==============================================================================#
#                                  VARIABLES                                   #
#==============================================================================#

# Names
PGM_NAME	= philo
PROJ_NAME	= PHILOSOPHERS
BUILD_NAME	= build

# Paths
INC_PATH = include
SRC_PATH = src
BUILD_PATH	= build

# Source files
SRC = $(addprefix $(SRC_PATH)/, \
	main.c \
	actions.c \
	ft_safe_atol.c \
	ft_cleanup_simulation.c \
	ft_get_timestamp.c \
	ft_init_simulation.c \
	ft_is_running.c \
	ft_monitoring_routine.c \
	ft_parse_rules.c \
	ft_routine.c \
	ft_safe_usleep.c \
	ft_start_simulation.c \
	mutex_utils.c \
	print_utils.c \
)

# Object files
OBJ = $(addprefix $(BUILD_PATH)/, $(notdir $(SRC:.c=.o)))

# Compiler and Flags
CC = cc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -g
ASAN = -fsanitize=address
INC = -I$(INC_PATH)
EXTRA_LIBS = -lpthread

# Utility Commands
MKDIR			= mkdir -p
RM				= rm -f
RM_REC_FORCE	= rm -rf
ECHO			= echo

# Print
PREFIX_GREEN = $(GREEN)[$(PROJ_NAME)]$(RESET)
PREFIX_RED = $(RED)[$(PROJ_NAME)]$(RESET)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re

all: $(PGM_NAME)

$(PGM_NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(ASAN) $(INC) $(OBJ) $(EXTRA_LIBS) -o $@
	@$(ECHO) "$(PREFIX_GREEN) Executable compiled: $(PGM_NAME)"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c | $(BUILD_PATH)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	@$(MKDIR) $(BUILD_NAME)
	@$(ECHO) "$(PREFIX_GREEN) Object files directory created: $(BUILD_NAME)"

clean:
	@$(RM_REC_FORCE) $(BUILD_PATH)
	@$(ECHO) "$(PREFIX_RED) Object files directory removed: $(BUILD_NAME)"

fclean: clean
	@$(RM) $(PGM_NAME)
	@$(ECHO) "$(PREFIX_RED) Executable removed: $(PGM_NAME)"

re: fclean all