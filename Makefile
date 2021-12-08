NAME 		= pipex

SRC_FILES 	= 	src/pipex.c \
				src/pipex_utils.c \
				src/ft_split.c \
				src/ft_putstr_fd.c \
				src/ft_substr.c \
				src/ft_strlen.c \
				src/ft_strnstr.c \
				src/ft_strncmp.c \
				src/ft_strjoin.c

SRC_BONUS 	= 	src/pipex_bonus.c \
				src/pipex_utils_bonus.c \
				src/pipex_utils.c \
				src/ft_split.c \
				src/ft_putstr_fd.c \
				src/ft_substr.c \
				src/ft_strlen.c \
				src/ft_strnstr.c \
				src/ft_strncmp.c \
				src/ft_strjoin.c \
				src/get_next_line.c \
				src/get_next_line_utils.c

OBJ_SRC 	= $(SRC_FILES:.c=.o)

OBJ_BONUS 	= $(SRC_BONUS:.c=.o)

CC 			= gcc

RM 			= rm -f

LIBH 		= include/pipex.h

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_SRC)
			$(CC) $(FLAGS) $(OBJ_SRC) -o $(NAME)

bonus: $(OBJ_BONUS)
			$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME)

%.o:	%.c $(LIBH)
			$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_SRC) $(OBJ_BONUS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
