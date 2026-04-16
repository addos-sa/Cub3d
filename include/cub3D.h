/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:11:56 by frasanch          #+#    #+#             */
/*   Updated: 2026/04/16 11:08:32 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720
# define LEFT 263
# define RIGHT 262
# define PI 3.14159265359

# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_ray
{
	double	cos_a;
	double	sin_a;
	double	ray_x;
	double	ray_y;
	double	wall_hit;
}	t_ray;

typedef struct s_screen
{
	char    **grid;
	char	*floor_path;
	char	*ceiling_path;
    int     rgb_floor;
	int		rgb_ceiling;
	int		n_player;
	int		height;
	int		width;
}	t_screen;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_player
{
	t_point	position;
	double	angle;
	bool	k_up;
	bool	k_down;
	bool	k_right;
	bool	k_left;
	bool	r_left;
	bool	r_right;
}	t_player;


typedef struct s_textures
{
	char			*e_path;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	mlx_texture_t	*east_t;
	mlx_texture_t	*north_t;
	mlx_texture_t	*south_t;
	mlx_texture_t	*west_t;
}	t_textures;

typedef struct s_cub3D
{
	t_screen		*screen;
	t_player		*player;
	t_textures		*textures;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*ac_text;
	bool			game_running;
	int 			image_c;
	char			**map_copy;
}	t_cub3D;

/*-------------------------main--------------------------*/

t_cub3D		*init_game(t_cub3D *game);
void		game_loop(void *param);

			/*--------------bad--------------*/

int			bad_arg(int argc);
char		bad_init(t_cub3D *game, int part);

			/*-------------utils-------------*/

const char	*skip_spaces(const char *s);
int	is_empty_line(char *line);
int	is_space_or_empty(char c);
t_ray	*create_ray(double start_x, int i, t_cub3D *game);


/*-------------------------parse-------------------------*/

int			parse(t_cub3D *game, char *map_path);
int			parse_map(t_cub3D *game, int fd, char *map_path);
int			parse_paths(t_cub3D *game, char **file, int *i);
int			parse_player(t_cub3D *game);
char		**get_map(int fd, char *map_path);

/*----------------------ray_casting----------------------*/

int	draw_loop(t_cub3D *game);

/*-----------------------validation----------------------*/

int			validate_colours(t_screen *screen);
int			validate_map(t_screen *screen);
int			validate_texture_files(t_textures *textures);
int			validate_parsed_data(t_cub3D *game);


const char	*skip_spaces(const char *s);
int			is_empty_line(char *line);
int			is_space_or_empty(char c);

#endif