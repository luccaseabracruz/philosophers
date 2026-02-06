# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseabra- <lseabra-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 16:37:00 by lseabra-          #+#    #+#              #
#    Updated: 2026/02/06 12:03:07 by lseabra-         ###   ########.fr        #
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
	utils.c \
)

# Object files
OBJ = $(addprefix $(BUILD_PATH)/, $(notdir $(SRC:.c=.o)))

# Compiler and Flags
CC = cc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -g
INC = -I$(INC_PATH)
EXTRA_LIBS = -lpthread

# Utility Commands
MKDIR	= mkdir -p
RM = rm
RM_REC_FORCE = rm -rf

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

.PHONY: all clean fclean re

all: $(PGM_NAME)

$(PGM_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(EXTRA_LIBS) -o $@

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c | $(BUILD_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD_PATH):
	$(MKDIR) $(BUILD_NAME)

clean:
	$(RM_REC_FORCE) $(BUILD_PATH)

fclean: clean
	$(RM) $(PGM_NAME)

re: fclean all