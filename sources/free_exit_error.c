#include "../includes/so_long.h"

void	check_if_ber_file(int argc, char **argv)
{
	char	*filename;
	int		len;

	if (argc == 2)
	{
		filename = argv[argc - 1];
		len = ft_strlen(filename);
		if (len >= 4 && ft_strcmp(filename + len - 4, ".ber") == 0)
			return ;
	}
	write(2, "\033[1;01mError\n\033[0;00m", 13);
	write(2, "Expected Argument: ", 19);
	write(2, "\033[1;31m'./so_long <file.ber>'\n\033[0;00m", 30);
	exit(0);
}

int	does_map_exist(int fd)
{
	if (fd == -1)
	{
		write(2, "\033[1;01mError\n\033[0;00m", 13);
		write(2, "\033[1;31m-Check if file exists\n\033[0;00m", 29);
		write (1, "-If file exists use command: 'chmod +r <file.ber>'\n", 51);
		exit(0);
	}
	return (0);
}

void	free_and_exit(char *str, void *mlx_ptr)
{
	if (mlx_ptr)
		free(mlx_ptr);
	if (str)
		free(str);
	exit (0);
}

void	free_str(char *str)
{
	write(2, "\033[1;01mError\n\033[0;00m", 13);
	write(2, "\033[1;31mAllocation of Memory Failed\n\033[0;00m", 35);
	if (str)
		free(str);
	exit(1);
}

void	free_str_and_temp(char *str, char *temp)
{
	if (str)
		free(str);
	if (temp)
		free(temp);
	exit(1);
}
