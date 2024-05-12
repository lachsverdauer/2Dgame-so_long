#include "../includes/so_long.h"

char	*free_string(char *string, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(string, buffer);
	return (free(string), temp);
}

char	*loadmap(int fd)
{
	static char	*string;
	char		*buffer;
	int			byte_read;

	string = ft_calloc(1, 1);
	if (string == NULL)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(string), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), NULL);
		buffer[byte_read] = 0;
		string = free_string(string, buffer);
	}
	return (free(buffer), string);
}

void	mlx_stuff(t_game *game)
{
	game->temp = game->size_c;
	game->moves = 0;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		free_and_exit(game->str, game->mlx_ptr);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->line_l - 2) * 64
			+ 64, (check_lines(game) * 64 + 64), "so_long");
	if (!game->win_ptr)
		free_and_exit(game->str, game->mlx_ptr);
	set_pictures(game);
	render_map(game);
	mlx_hook(game->win_ptr, 2, 1L >> 0, &key_press, game);
	mlx_hook(game->win_ptr, 17, 0, mlx_loop_end, game->mlx_ptr);
	mlx_loop(game->mlx_ptr);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_floor);
	mlx_destroy_image(game->mlx_ptr, game->img_player);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_collectable);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_and_exit(game->str, game->mlx_ptr);
}

void	map_check(char *temp, t_game *game)
{
	if (!valid_map(temp) || !path_check(temp, game->line_l, game))
	{
		free(temp);
		free(game->str);
		exit(1);
	}
	if (game->line_l > 31 || game->line_l == -1
		|| check_lines(game) > 15)
	{
		write(2, "\033[1;01mError\n\033[0;00m", 13);
		write(2, "\033[1;31mMap too big\n\033[0;00m", 19);
		free_str_and_temp(game->str, temp);
		exit(1);
	}
	free(temp);
	game->collected_c = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	char	*temp;

	check_if_ber_file(argc, argv);
	fd = open(argv[1], O_RDONLY);
	does_map_exist(fd);
	game.str = loadmap(fd);
	if (game.str == NULL)
		free_str(game.str);
	close(fd);
	temp = ft_strdup(game.str);
	if (temp == NULL)
	{
		write(2, "\033[1;01mError\n\033[0;00m", 13);
		write(2, "\033[1;31mAllocation of Memory Failed\n\033[0;00m", 35);
		return (free_str_and_temp(game.str, temp), 0);
	}
	game.line_l = (line_l(game.str) + 1);
	map_check(temp, &game);
	game.pos_p = pos_p(game.str);
	game.size_c = count_collectable(game.str);
	mlx_stuff(&game);
	return (0);
}
