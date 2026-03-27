/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:11:56 by frasanch          #+#    #+#             */
/*   Updated: 2026/03/27 10:57:32 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

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
	t_screen	*screen;
	t_player	*player;
	t_textures	*textures;
	mlx_t		*mlx;
	bool		game_running;
	int 		image_c;
	char		**map_copy;
}	t_cub3D;


/*------------------------parse------------------------*/

int			parse(t_cub3D *game, char *map_path);
int			parse_map(t_cub3D *game, int fd, char *map_path);
char		**get_map(int fd, char *map_path);
int			parse_paths(t_cub3D *game, char **file, int *i);
int			parse_player(t_cub3D *game);

/*----------------------validation---------------------*/

int			validate_parsed_data(t_cub3D *game);
int			validate_texture_files(t_textures *textures);
int			validate_colours(t_screen *screen);

t_cub3D		*init_game(char *map_path);
const char	*skip_spaces(const char *s);
int			is_empty_line(char *line);
int			is_space_or_empty(char c);

#endif