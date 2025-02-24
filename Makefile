# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:32:02 by anareval          #+#    #+#              #
#    Updated: 2025/02/24 15:05:35 by anareval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast
RM = rm -f

LIBMLX = ./lib/MLX42
HEADERS = -I ./include -I $(LIBMLX)/include
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS =			so_long.c

OBJS = $(SRCS:.c=.o)

all: libmlx $(NAME)

libmlx:
	@if [ ! -f "$(LIBMLX)/build/libmlx42.a" ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	fi

%.o: %.c	
		@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<  && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
		@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
		@$(RM) $(OBJS)
		@$(RM) -rf $(LIBMLX)/build

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
