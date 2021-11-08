# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 16:29:37 by zminhas           #+#    #+#              #
#    Updated: 2021/11/08 18:58:26 by zminhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS	=	philosophers.c

OBJS	=	${SRCS:.c=.o}

NAME	=	philo.a

EXEC	=	philo

UTILS_PATH	=	./utils

.c.o:
		@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

all:	${OBJS}
		@clear
		@make -C ${UTILS_PATH}
		@mv ${UTILS_PATH}/libft.a $(NAME)
		@ar -rcs $(NAME) ${OBJS}
		@gcc -Wall -Wextra -Werror $(NAME) -o $(EXEC)
		@echo "${GREEN}philo created !${RESET}"

clean:
		@clear
		@rm -f ${OBJS}
		@rm -f $(NAME)
		@make clean -C ${UTILS_PATH}
		@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
		@clear
		@rm -f ${OBJS}
		@rm -f $(NAME)
		@rm -f $(EXEC)
		@make fclean -C ${UTILS_PATH}
		@echo "${RED}fclean done !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re
