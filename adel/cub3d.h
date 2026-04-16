/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:44:26 by addos-sa          #+#    #+#             */
/*   Updated: 2026/04/14 13:36:14 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720
# define LEFT 263
# define RIGHT 262
# define PI 3.14159265359

# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include "./src/MLX42/include/MLX42/MLX42.h"
# include "./src/libft/libft.h"
# include "./src/ft_printf/ft_printf.h"

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
	char	**grid;
	int		m_width;
	int		m_height;
	int		rgb_floor;
	int		rgb_ceiling;
}	t_screen;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_player
{
	t_point	*pos;
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
	char			*so_path;
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
	mlx_texture_t	*ac_text;
	mlx_t			*mlx;
	mlx_image_t		*img;
	bool			game_running;
	int 			image_c;
	char			**map_copy;
}	t_cub3D;

//INICIALIZATION
int		ini_game(t_cub3D *game);
int		ini_player(t_player *player);
int		ini_texture(t_textures *textures);
int		ini_screen(t_screen *screen);
t_ray	*ini_ray(double start_x, int i, t_cub3D *game);

//CLEAN UP
free_player(t_player *player);
free_texture(t_textures *textures);
free_game(t_cub3D *game);

//KEYS
void	case_key_pressed(t_cub3D *game, double cos_ang, double sin_ang, int nm);
void	which_key(t_cub3D *game, double cf, double sf, double p_y, double p_x);
void	key_pressed(t_cub3D *game);
void	player_movement(t_cub3D *game);
void	game_loop(void *param);
int		is_wall(t_cub3D *game, double pos_x, double pos_y);

//MATH
double			pythagoras(double x, double y);
mlx_texture_t	*wl_text(t_cub3D *game, double ray_x, double ray_y, double ang);
void			set_wall_texture(t_cub3D *game, t_ray *ray, int side);

//GAME
void	game_loop(void *param);
int		draw_loop(t_cub3D *game);

#endif
