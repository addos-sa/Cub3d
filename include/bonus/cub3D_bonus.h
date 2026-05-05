/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:11:56 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/05 10:04:08 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# include "../../lib/libft/libft.h"
# include "../../lib/ft_printf/ft_printf.h"
# include "../../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_dda
{
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_dst;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
}	t_dda;

typedef struct s_ray
{
	double			cos_a;
	double			sin_a;
	double			ray_x;
	double			ray_y;
	double			wall_hit;
}	t_ray;

typedef struct s_screen
{
	char			**grid;
	int				rgb_floor;
	int				rgb_ceiling;
	int				n_player;
	int				height;
	int				width;
}	t_screen;

typedef struct s_point
{
	double			x;
	double			y;
}	t_point;

typedef struct s_textures
{
	mlx_texture_t	*east_t;
	mlx_texture_t	*north_t;
	mlx_texture_t	*south_t;
	mlx_texture_t	*west_t;
	mlx_texture_t	*door_t;
}	t_textures;

typedef struct s_player
{
	t_point			position;
	double			angle;
	bool			k_up;
	bool			k_down;
	bool			k_right;
	bool			k_left;
	bool			r_left;
	bool			r_right;
	bool			mouse;
	bool			map;
}	t_player;

typedef struct s_paths
{
	char			*e_path;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*d_path;
	char			*floor_path;
	char			*ceiling_path;
}	t_paths;

typedef struct s_cub3D
{
	t_screen		*screen;
	t_textures		*textures;
	t_player		*player;
	t_paths			*paths;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*ac_text;
	bool			game_running;
	int				image_c;
	char			**map_copy;
}	t_cub3D;

/*-------------------------main--------------------------*/

int				free_game(t_cub3D *game, int mode);
int				free_file(char **file, int type);

			/*--------------bad--------------*/

int				bad_arg(int argc);
void			*bad_init(t_cub3D *game, int part);
int				bad_game(int i);

			/*-------------inits-------------*/

t_cub3D			*init_game(t_cub3D *game);

			/*-----------key_press-----------*/

void			game_loop(void *param);

			/*-------------utils-------------*/

char			*skip_spaces(const char *s);
int				is_empty_line(char *line);
int				is_space_or_empty(char c);
t_ray			*create_ray(double start_x, t_cub3D *game);
void			init_image(t_cub3D *game);

/*-------------------------parse-------------------------*/

int				parse(t_cub3D *game, char *map_path);
int				parse_map(t_cub3D *game, int fd, char *map_path);
int				parse_paths(t_cub3D *game, char **file, int *i);
int				parse_player(t_cub3D *game);
char			**get_map(int fd, char *map_path);
int				get_color_hex(char *rgb_str);

/*----------------------ray_casting----------------------*/

			/*----------calculations----------*/

int				is_wall(t_cub3D *game, double pos_x, double pos_y);
mlx_texture_t	*wl_text(t_cub3D *game, double ray_x, double ray_y, double ang);
void			set_wall_texture(t_cub3D *game, t_ray *ray, t_dda *info);
void			calculate_for_dda(t_cub3D *game, t_ray *ray, t_dda *info);
void			wall_loop(t_cub3D *game, t_dda *info);

			/*---------draw_functions---------*/

int				draw_loop(t_cub3D *game);
void			draw_back(t_cub3D *game);
void			pixeling(int x, int y, int color, t_cub3D *game);

			/*------------graphics------------*/

bool			touch_wall(double ray_x, double ray_y, t_cub3D *game);
int				text_to_color(t_cub3D *game, int tex_x, int tex_y);

/*-----------------------validation----------------------*/

int				validate_colours(t_paths *paths);
int				validate_map(t_screen *screen);
int				validate_texture_files(t_paths *paths);
int				validate_parsed_data(t_cub3D *game);

/*-------------------------extra-------------------------*/

void			mouse_movement(t_cub3D *game);
void			key_hook_handler(mlx_key_data_t keydata, void *param);
void			draw_minimap(t_cub3D *game);
void			is_there_a_door(t_cub3D *game);

#endif