# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 16:21:55 by knishiok          #+#    #+#              #
#    Updated: 2023/10/20 20:45:54 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = -I includes

LIB = libft/libft.a

NAME = exec

SERVER = server
CLIENT = client

SERVER_OBJS = srcs/server.o
CLIENT_OBJS = srcs/client.o srcs/client_utils.o

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_BONUS_OBJS = srcs/server_bonus.o
CLIENT_BONUS_OBJS = srcs/client_bonus.o srcs/client_bonus_utils.o

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SERVER_OBJS) $(LIB)
	$(CC) $(CFLAGS) $^ $(INC) -o $@

$(CLIENT): $(CLIENT_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

$(SERVER_BONUS): $(SERVER_BONUS_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

$(CLIENT_BONUS):$(CLIENT_BONUS_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIB):
	make -C libft

clean:
	make clean -C libft
	$(RM) $(SERVER_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_OBJS) $(CLIENT_BONUS_OBJS)

fclean:
	make fclean -C libft
	$(RM) $(SERVER_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)


re: fclean all

.PHONY: all clean fclean
