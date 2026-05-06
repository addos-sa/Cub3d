/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frasanch <frasanch@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:11:04 by frasanch          #+#    #+#             */
/*   Updated: 2026/05/05 12:27:54 by frasanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus/cub3D_bonus.h"

void	good_angle(t_cub3D *game)
{
	char	dir;
	int		x;
	int		y;

	x = game->player->position.x;
	y = game->player->position.y;
	dir = game->screen->grid[y][x];
	if (dir == 'N')
		game->player->angle = 3 * PI/2;
	else if (dir == 'W')
		game->player->angle = PI;
	else if (dir == 'E')
		game->player->angle = 0;
}

static void	close_handler(void *param)
{
	t_cub3D	*game;

	game = (t_cub3D *)param;
	free_game(game, 0);
	exit(0);
}

static void	game_running(t_cub3D *game)
{
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_close_hook(game->mlx, &close_handler, game);
	mlx_key_hook(game->mlx, &key_hook_handler, game);
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_DISABLED);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_cub3D	*game;

	if (argc != 2)
		return (bad_arg(argc));
	if (ft_strlen(argv[1]) == 0)
		return (bad_arg(0));
	game = (t_cub3D *)malloc(sizeof(t_cub3D));
	if (!game)
		return (bad_game(1));
	game = init_game(game);
	if (parse(game, argv[1]))
		return (free_game(game, 1));
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		return (free_game(game, 1));
	init_image(game);
	if (game->game_running)
		game_running(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	return (free_game(game, 0));
}
