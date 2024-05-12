#include "so_long_bonus.h"

void	set_pictures(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall.xpm",
			&img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "./img/floor.xpm",
			&img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "./img/player.xpm",
			&img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm",
			&img_width, &img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			"./img/collect.xpm", &img_width, &img_height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx_ptr, "./img/enemy.xpm",
			&img_width, &img_height);
	game->img_pu = mlx_xpm_file_to_image(game->mlx_ptr, "./img/pu.xpm",
			&img_width, &img_height);
	game->img_pd = mlx_xpm_file_to_image(game->mlx_ptr, "./img/pd.xpm",
			&img_width, &img_height);
	game->img_pr = mlx_xpm_file_to_image(game->mlx_ptr, "./img/pr.xpm",
			&img_width, &img_height);
	game->img_pl = mlx_xpm_file_to_image(game->mlx_ptr, "./img/pl.xpm",
			&img_width, &img_height);
}

void	render_map2(int i, int k, int n, t_game *game)
{
	while (game->str[i])
	{
		if (game->str[i] == '\n')
		{
			n = -1;
			k++;
		}
		else if (game->str[i] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_exit, ((n) * 64), (k * 64));
		else if (game->str[i] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_collectable, ((n) * 64), (k * 64));
		else if (game->str[i] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_player, ((n) * 64), (k * 64));
		else if (game->str[i] == 'X')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_enemy, ((n) * 64), (k * 64));
		i++;
		n++;
	}
}

void	render_map3(int i, int k, int n, t_game *game)
{
	while (game->str[i])
	{
		if (game->str[i] == '\n')
		{
			n = -1;
			k++;
		}
		else if (game->str[i] == 'U')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_pu, ((n) * 64), (k * 64));
		else if (game->str[i] == 'I')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_pd, ((n) * 64), (k * 64));
		else if (game->str[i] == 'O')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_pl, ((n) * 64), (k * 64));
		else if (game->str[i] == 'L')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_pr, ((n) * 64), (k * 64));
		i++;
		n++;
		on_screen_moves(game);
	}
}

void	render_map(t_game *game)
{
	int	i;
	int	k;
	int	n;

	i = 0;
	k = 0;
	n = 0;
	while (game->str[i])
	{
		if (game->str[i] == '\n')
		{
			n = -1;
			k++;
		}
		else if (game->str[i] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_wall, ((n) * 64), (k * 64));
		else if (game->str[i] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_floor, ((n) * 64), (k * 64));
		render_map2(i, k, n, game);
		render_map3(i, k, n, game);
		i++;
		n++;
	}
}
