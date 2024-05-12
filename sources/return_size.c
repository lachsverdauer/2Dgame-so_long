#include "../includes/so_long.h"

int	pos_p(char *str)
{
	int	p;

	p = 0;
	while (str[p] != 'P')
		p++;
	return (p);
}

int	count_collectable(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			c++;
		i++;
	}
	return (c);
}

int	check_lines(t_game *game)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (game->str[i])
	{
		if (game->str[i] == '\n')
			k++;
		i++;
	}
	return (k);
}

int	line_l(char *str)
{
	int	length;

	length = 0;
	if (!str || !str[0])
		return (-1);
	while (str[length] && str[length] != '\n')
		length++;
	return (length);
}

void	set_did_and_i_to_zero(t_game *game)
{
	game->did = 0;
	game->i = 0;
}
