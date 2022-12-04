SRC = $(addprefix src/, decode.c main.c morse.c)
INC = ./includes
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = morse
RM = rm -rf

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) $(NAME)

re: clean all