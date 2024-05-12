#include "so_long_bonus.h"

int	move_up(char *str, t_game *game)
{
	int	zero;

	zero = game->pos_p;
	if (str[game->pos_p - game->line_l] == '1')
		return (0);
	if (str[game->pos_p - game->line_l] == 'X')
		return (write(1, "\033[1;35mA BEE STUG YOU\n\033[0;00m", 22),
			mlx_loop_end(game->mlx_ptr), 0);
	else if (str[game->pos_p - game->line_l] == 'E'
		&& game->size_c > 0)
		return (0);
	else if (str[game->pos_p - game->line_l] == 'E'
		&& game->size_c == 0)
	{
		write(1, "\033[1;32mYou Finished The Game\n\033[0;00m", 29);
		mlx_loop_end(game->mlx_ptr);
		return (0);
	}
	if (game->str[game->pos_p - game->line_l] == 'C')
		print_collection(game);
	game->str[game->pos_p - game->line_l] = 'P';
	game->pos_p -= game->line_l;
	game->str[zero] = '0';
	game->moves++;
	return (1);
}

int	move_down(char *str, t_game *game)
{
	int	zero;

	zero = game->pos_p;
	if (str[game->pos_p + game->line_l] == '1')
		return (0);
	if (str[game->pos_p + game->line_l] == 'X')
		return (write(1, "\033[1;35mA BEE STUG YOU\n\033[0;00m", 22),
			mlx_loop_end(game->mlx_ptr), 0);
	else if (str[game->pos_p + game->line_l] == 'E'
		&& game->size_c > 0)
		return (0);
	else if (str[game->pos_p + game->line_l] == 'E'
		&& game->size_c == 0)
	{
		write(1, "\033[1;32mYou Finished The Game\n\033[0;00m", 29);
		mlx_loop_end(game->mlx_ptr);
		return (0);
	}
	if (game->str[game->pos_p + game->line_l] == 'C')
		print_collection(game);
	game->str[game->pos_p + game->line_l] = 'P';
	game->pos_p += game->line_l;
	game->str[zero] = '0';
	game->moves++;
	return (1);
}

int	move_right(char *str, t_game *game)
{
	int	zero;

	zero = game->pos_p;
	if (str[game->pos_p + 1] == '1')
		return (0);
	if (str[game->pos_p + 1] == 'X')
		return (write(1, "\033[1;35mA BEE STUG YOU\n\033[0;00m", 22),
			mlx_loop_end(game->mlx_ptr), 0);
	else if (str[game->pos_p + 1] == 'E'
		&& game->size_c > 0)
		return (0);
	else if (str[game->pos_p + 1] == 'E'
		&& game->size_c == 0)
		return (write(1, "\033[1;32mYou Finished The Game\n\033[0;00m", 29),
			mlx_loop_end(game->mlx_ptr), 0);
	if (game->str[game->pos_p + 1] == 'C')
		print_collection(game);
	game->str[game->pos_p + 1] = 'P';
	game->pos_p += 1;
	game->str[zero] = '0';
	game->moves++;
	return (1);
}

int	move_left(char *str, t_game *game)
{
	int	zero;

	zero = game->pos_p;
	if (str[game->pos_p - 1] == '1')
		return (0);
	if (str[game->pos_p - 1] == 'X')
		return (write(1, "\033[1;35mA BEE STUG YOU\n\033[0;00m", 22),
			mlx_loop_end(game->mlx_ptr), 0);
	else if (str[game->pos_p - 1] == 'E'
		&& game->size_c > 0)
		return (0);
	else if (str[game->pos_p - 1] == 'E'
		&& game->size_c == 0)
	{
		write(1, "\033[1;32mYou Finished The Game\n\033[0;00m", 29);
		mlx_loop_end(game->mlx_ptr);
		return (0);
	}
	if (game->str[game->pos_p - 1] == 'C')
		print_collection(game);
	game->str[game->pos_p - 1] = 'P';
	game->pos_p -= 1;
	game->str[zero] = '0';
	game->moves++;
	return (1);
}

int	key_press(int keysym, t_game *game)
{
	if ((keysym == KEY_W || keysym == KEY_UP) && move_up(game->str, game))
		return (render_up(game), on_screen_moves(game), 0);
	else if ((keysym == KEY_S || keysym == KEY_DOWN) && move_down(game->str,
			game))
		return (render_down(game), on_screen_moves(game), 0);
	else if ((keysym == KEY_A || keysym == KEY_LEFT) && move_left(game->str,
			game))
		return (render_left(game), on_screen_moves(game), 0);
	else if ((keysym == KEY_D || keysym == KEY_RIGHT) && move_right(game->str,
			game))
		return (render_right(game), on_screen_moves(game), 0);
	else if (keysym == KEY_ESC)
	{
		write(1, "\033[1;35mLeft Game Pressing 'ESC'\n\033[0;00m", 32);
		mlx_loop_end(game->mlx_ptr);
		return (0);
	}
	return (0);
}
