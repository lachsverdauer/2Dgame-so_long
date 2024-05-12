#include "../includes/so_long.h"

int	check_player_exit_and_collectable(char *str)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			p++;
		else if (str[i] == 'E')
			e++;
		else if (str[i] == 'C')
			c++;
		i++;
	}
	if ((p != 1 || e != 1 || c < 1))
		return (0);
	return (1);
}

int	check_if_only_wanted_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P' || str[i] == 'E' || str[i] == 'C' || str[i] == '\n'
			|| str[i] == '1' || str[i] == '0')
			i++;
		else
			return (0);
	}
	return (1);
}

char	*fill_path2(char *str, int len, t_game *game)
{
	if (str[game->i + len] == '0' || str[game->i + len] == 'C')
		str[game->i + len] = 'I';
	if (str[game->i - 1] == 'E')
		str[game->i - 1] = 'e';
	if (str[game->i + 1] == 'E')
		str[game->i + 1] = 'e';
	if (str[game->i + len] == 'E')
		str[game->i + len] = 'e';
	if (str[game->i - len] == 'E')
		str[game->i - len] = 'e';
	if ((str[game->i + len] == '0' || str[game->i + len] == 'C') || (str[game->i
				- 1] == 'E') || (str[game->i + 1] == 'E') || (str[game->i
				+ len] == 'E') || (str[game->i - len] == 'E'))
		game->did++;
	return (str);
}

char	*fill_path(char *str, int len, t_game *game)
{
	if (str[game->i] == 'P')
		str[game->i] = 'I';
	if (str[game->i] == 'I')
	{
		if (str[game->i - 1] == '0' || str[game->i - 1] == 'C')
		{
			str[game->i - 1] = 'I';
			game->did++;
		}
		if (str[game->i + 1] == '0' || str[game->i + 1] == 'C')
		{
			str[game->i + 1] = 'I';
			game->did++;
		}
		if (str[game->i - len] == '0' || str[game->i - len] == 'C')
		{
			str[game->i - len] = 'I';
			game->did++;
		}
		fill_path2(str, len, game);
	}
	game->i++;
	return (str);
}

int	path_check(char *str, int len, t_game *game)
{
	game->i = 0;
	game->did = 0;
	while (str[game->i] != '\0')
	{
		fill_path(str, len, game);
		if (str[game->i] == '\0')
		{
			if (game->did == 0)
			{
				while (str[game->did] != '\0')
				{
					if (str[game->did] != '1' && str[game->did] != 'I'
						&& str[game->did] != '\n' && str[game->did] != '0'
						&& str[game->did] != 'e')
						return (write(2, "\033[1;01mError\n\033[0;00m", 13),
							write(2, "\033[1;31mInvalid Map\n\033[0;00m", 19),
							0);
					game->did++;
				}
				return (1);
			}
			set_did_and_i_to_zero(game);
		}
	}
	return (0);
}
