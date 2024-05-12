#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		moves;
	int		pos_p;
	int		size_c;
	int		line_l;
	int		did;
	int		i;
	int		collected_c;
	int		temp;
	char	*str;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectable;
}			t_game;

/* map check */
int			path_check(char *str, int len, t_game *game);
int			check_player_exit_and_collectable(char *str);
int			check_if_only_wanted_characters(char *str);
int			valid_map(char *str);

/* movement */
int			key_press(int keysym, t_game *game);
void		dead(t_game *game);

/* errors and frees */
int			does_map_exist(int fd);
void		free_str_and_temp(char *str, char *temp);
void		check_if_ber_file(int argc, char **argv);
void		free_and_exit(char *str, void *mlx_ptr);
void		free_str(char *str);

/* values */
int			count_collectable(char *str);
int			pos_p(char *str);
int			check_lines(t_game *game);
int			line_l(char *str);
void		set_did_and_i_to_zero(t_game *game);

/* window */
void		set_pictures(t_game *game);
void		render_map2(int i, int k, int n, t_game *game);
void		render_map(t_game *game);
void		render_up(t_game *game);
void		render_down(t_game *game);
void		render_left(t_game *game);
void		render_right(t_game *game);

/* utils */
int			ft_strcmp(char *s1, char *s2);

void		write_moves(t_game *game);
void		write_number(int number);
void		print_collection(t_game *game);

#endif
