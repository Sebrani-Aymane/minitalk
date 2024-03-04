CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

SRC_c = client.c
SRC_s = server.c

OBJ_c = $(SRC_c:.c=.o)
OBJ_s = $(SRC_s:.c=.o)


ALL = $(OBJ_c) $(OBJ_s)

NAME = server client

all : $(NAME)

%.o : %.c minitalk.h
	$(CC) $(FLAGS) -c $< -o $@

server : $(SRC_s)
	$(CC) $(FLAGS) $(SRC_s) -o $@

client : $(SRC_c)
	$(CC) $(FLAGS) $(SRC_c) -o $@


clean :
	$(RM) $(ALL)
fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY : all clean fclean re
