CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = server
CLIENT = client

SRC_c = client.c utils2.c
SRC_s = server.c utils.c utils2.c

C_OBJ = $(SRC_c:.c=.o)
S_OBJ = $(SRC_s:.c=.o)


all: $(NAME) $(CLIENT)

$(NAME): $(S_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(C_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(C_OBJ) $(S_OBJ)

fclean: clean
	$(RM) $(NAME) $(CLIENT)

re: fclean all

.PHONY : all clean fclean re
