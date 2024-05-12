#include "../includes/so_long.h"

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
				game->img_player, ((n) * 64), (k * 64));
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
				game->img_player, ((n) * 64), (k * 64));
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
				game->img_player, ((n) * 64), (k * 64));
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
				game->img_player, ((n) * 64), (k * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_floor, ((++n) * 64), (k * 64));
			return ;
		}
		i++;
		n++;
	}
}
