#include "so_long_bonus.h"

int	check_new_lines(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] != '\0')
			result++;
		i++;
	}
	if (i - 1 <= 0)
		return (0);
	if (str[i] == '\0' && (str[i - 1] != '1'))
		return (0);
	if (result > 1)
		return (1);
	return (0);
}

int	check_vertical(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if ((str[i + 1] != '1' || str[i - 1] != '1') && (str[i
						+ 1] != '\0'))
				return (0);
			else if (!(str[i - 1] == '1') && (str[i + 1] == '\0'))
				return (0);
			i++;
		}
		else
			i++;
	}
	return (1);
}

int	check_horizontal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	while (str[i + 1] != '\0')
		i++;
	if (str[i] == '\n')
		i--;
	while (str[i - 1] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	check_line_l(char *str)
{
	int	prev_line_l;
	int	current_line_l;

	if (str == NULL)
		return (0);
	prev_line_l = -1;
	current_line_l = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
		{
			if (prev_line_l == -1)
				prev_line_l = current_line_l;
			else if (current_line_l != prev_line_l)
				return (0);
			current_line_l = 0;
		}
		else
			current_line_l++;
		str++;
	}
	if ((current_line_l > 0 && current_line_l != prev_line_l))
		return (0);
	return (1);
}

int	valid_map(char *str)
{
	if (!check_new_lines(str) || !check_vertical(str) || !check_horizontal(str)
		|| !check_line_l(str) || !check_if_only_wanted_characters(str)
		|| !check_player_exit_and_collectable(str))
	{
		write(2, "\033[1;01mError\n\033[0;00m", 13);
		write(2, "\033[1;31mInvalid Map\n\033[0;00m", 19);
		return (0);
	}
	return (1);
}
