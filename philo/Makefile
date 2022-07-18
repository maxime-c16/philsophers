# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 11:45:51 by mcauchy           #+#    #+#              #
#    Updated: 2022/06/16 15:50:41 by mcauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES 			=	main.c check.c utils.c init.c routine.c ft_itoa.c ft_strjoin.c \
					routine_utils.c monitoring.c utils_2.c

SRC_DIR 		=	srcs

DIR_OBJ 		=	.objs

SRCS 			=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJS 			=	$(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o)))

CC 				=	gcc

CFLAGS 			=	-Wall -Wextra -Werror -g3

NAME 			=	philo

HEADER  		=	includes/philo.h

all				: $(NAME)

$(NAME) 		: 	$(OBJS)
					clear
					@echo "Linking $(NAME)..."
					@$(CC) $(CFLAGS) $^ -pthread -o $@
					@sleep 1
					@clear
					@echo "Compilation done."
					@sleep 1
					@clear

$(DIR_OBJ)/%.o	:	$(SRC_DIR)/%.c $(HEADER)
					@mkdir -p $(@D)
					@echo "Compiling $(notdir $<)..."
					@$(CC) $(CFLAGS) -o $@ -c $<

clean			:
					@/bin/rm -f $(OBJS)
					@/bin/rm -rf $(DIR_OBJ)
					@clear
					@echo "Cleaned."

fclean			:	clean
					@clear
					@/bin/rm -f $(NAME)
					@clear
					@echo "Fully cleaned."

re				:	fclean  all

.PHONY  		: 	all clean fclean fclean re
