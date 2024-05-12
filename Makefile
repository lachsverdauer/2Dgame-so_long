NAME = so_long

NAMEBONUS = so_long_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror

SOURCE = sources/free_exit_error.c\
	sources/main.c\
	sources/map_check.c\
	sources/map_check2.c\
	sources/move.c\
	sources/return_size.c\
	sources/utils.c\
	sources/window.c\
	sources/window2.c\


SOURCE_BONUS = bonus/free_exit_error_bonus.c\
	bonus/main_bonus.c\
	bonus/map_check_bonus.c\
	bonus/map_check2_bonus.c\
	bonus/move_bonus.c\
	bonus/return_size_bonus.c\
	bonus/utils_bonus.c\
	bonus/window_bonus.c\
	bonus/window2_bonus.c\


OBJ = $(SOURCE:.c=.o)

OBJ_BONUS = $(SOURCE_BONUS:.c=.o)

LIBFT_PATH = libft

all: $(NAME)

bonus: $(NAMEBONUS)

$(NAME): $(OBJ)
	(cd libft && make)
	$(CC) $(FLAGS) $(SOURCE) libft/libft.a -lmlx -lXext -lX11 -o $(NAME)
$(NAMEBONUS): $(OBJ_BONUS)
	(cd libft && make)
	$(CC) $(FLAGS) $(SOURCE_BONUS) libft/libft.a -lmlx -lXext -lX11 -o $(NAMEBONUS)
%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf sources/*.o
	@rm -rf bonus/*.o
	(cd libft && make clean)


fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAMEBONUS)
	(cd libft && make fclean)

re: fclean all

re_bonus: fclean bonus
