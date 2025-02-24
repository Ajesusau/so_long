# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:32:02 by anareval          #+#    #+#              #
#    Updated: 2025/02/24 18:12:46 by anareval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast
RM = rm -f

LIBMLX = 	./lib/MLX42
LIBFT =		./lib/Libft
HEADERS = 	-I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS = 		$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm \
		$(LIBFT)/libft.a

SRCS =		so_long.c

OBJS = $(SRCS:.c=.o)

all: libmlx libft $(NAME)

libmlx:
	@if [ ! -f "$(LIBMLX)/build/libmlx42.a" ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
		echo "Make LIBMLX"; \
	fi

libft:
	@if [ ! -f "$(LIBTF)/libft.a" ]; then \
		make -C $(LIBFT); \
		echo "Make LIBFT"; \
		make clean -C $(LIBFT); \
	fi


%.o: %.c	
		@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<  && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
		@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
		@$(RM) $(OBJS)
		@$(RM) -rf $(LIBMLX)/build
		@make fclean -C $(LIBFT)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx libft
