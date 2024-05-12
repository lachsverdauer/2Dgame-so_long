#include "../includes/so_long.h"

void	write_moves(t_game *game)
{
	game->moves++;
	write(1, "\033[1;36mMovements: \033[0;00m", 25);
	write_number(game->moves);
	write(1, "\n", 1);
}

void	write_number(int number)
{
	char	str[12];

	str[0] = '0';
	str[1] = '1';
	str[2] = '2';
	str[3] = '3';
	str[4] = '4';
	str[5] = '5';
	str[6] = '6';
	str[7] = '7';
	str[8] = '8';
	str[9] = '9';
	if (number > 9)
		write_number(number / 10);
	write(1, &str[number % 10], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	print_collection(t_game *game)
{
	write(1, "\033[1;32mYou collected \033[0;00m", 21);
	write_number(++game->collected_c);
	write (1, " Honey Jars out of ", 19);
	write_number(game->temp);
	write(1, "\n", 1);
	game->size_c--;
}
