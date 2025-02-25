# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 13:32:02 by anareval          #+#    #+#              #
#    Updated: 2025/02/25 20:36:43 by anareval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast
RM = rm -f

LIBMLX = 	./libs/MLX42
LIBFT =		./libs/Libft
HEADERS = 	-I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS = 		$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm \
		$(LIBFT)/libft.a

SRCS =		./sources/so_long.c \
			./sources/ft_read_map.c \
			./sources/ft_check_map.c \
			./sources/ft_draw_map.c

OBJS = $(SRCS:.c=.o)

all: st_msg libmlx libft $(NAME)
	@echo "✅ Build completed successfully!"

st_msg:
	@echo "📦 Creating the library: $(NAME)"

libmlx:
	@if [ ! -f "$(LIBMLX)/build/libmlx42.a" ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
		echo "Make LIBMLX"; \
	fi

libft:
	@if [ ! -f "$(LIBFT)/libft.a" ]; then \
		make -C $(LIBFT); \
		make clean -C $(LIBFT); \
	fi


%.o: %.c	
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@echo "🗑️ Deleting .o files..."
	@$(RM) $(OBJS)
	@$(RM) -rf $(LIBMLX)/build
	@echo "✅ Done!"
	@make fclean -C $(LIBFT)

fclean: clean
	@echo "🚮 Deleting $(NAME)..."
	@$(RM) $(NAME)
	@echo "✅ Done!"

re: re_msg fclean all

re_msg:
	@echo "🔄 Recreating the library..."

.PHONY: all clean fclean re libmlx libft
