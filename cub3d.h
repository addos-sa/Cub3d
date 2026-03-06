/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <addos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:44:26 by addos-sa          #+#    #+#             */
/*   Updated: 2026/03/06 12:39:18 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720
# define LEFT 65361
# define RIGHT 65363
# define PI 3.14159265359

# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include "./src/MLX42/include/MLX42/MLX42.h"
# include "./src/libft/libft.h"
# include "./src/ft_printf/ft_printf.h"

typedef struct s_screen
{
	char    **grid;
    int     m_width;
    int     m_height;
    int     rgb_floor;
	int		rgb_ceiling;
}	t_screen;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_player
{
	t_point	*position;
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
	t_screen	*screen;
	t_player	*player;
	t_textures	*textures;
	mlx_t		*mlx;
	bool		game_running;
	int 		image_c;
	char		**map_copy;
}	t_cub3D;

//INICIALIZATION
int	ini_game(t_cub3D *game);
int	ini_player(t_player *player);
int	ini_texture(t_textures *textures);
int	ini_screen(t_screen *screen);

//CLEAN UP
free_player(t_player *player);
free_textures(t_textures *textures);
free_game(t_cub3D *game);

//MATH
int	pythagoras(int x, int y);

#endif
