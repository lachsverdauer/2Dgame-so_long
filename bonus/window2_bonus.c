#include "so_long_bonus.h"

void	render_up(t_game *game)
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
		if (game->str[i] == 'P')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_pu, ((n) * 64), (k * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_floor, ((n) * 64), (++k * 64));
			return ;
		}
		i++;
		n++;
	}
}

void	render_down(t_game *game)
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
		if (game->str[i] == 'P')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_pd, ((n) * 64), (k * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_floor, ((n) * 64), (--k * 64));
			return ;
		}
		i++;
		n++;
	}
}

void	render_right(t_game *game)
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
		if (game->str[i] == 'P')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_pr, ((n) * 64), (k * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_floor, ((--n) * 64), (k * 64));
			return ;
		}
		i++;
		n++;
	}
}

void	render_left(t_game *game)
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
		if (game->str[i] == 'P')
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_pl, ((n) * 64), (k * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_floor, ((++n) * 64), (k * 64));
			return ;
		}
		i++;
		n++;
	}
}

void	on_screen_moves(t_game *game)
{
	char	*moves;
	char	*temp;

	moves = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_wall, 0, 0);
	temp = ft_strjoin("Mvs:", moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 1, 11, 0xFF0000, temp);
	free(temp);
	free(moves);
}
