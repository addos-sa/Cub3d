/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:11:56 by frasanch          #+#    #+#             */
/*   Updated: 2026/02/25 12:05:08 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

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
	t_point	position;
	double	angle;
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

t_cub3D	init_game(t_cub3D *game, char **map);

#endif