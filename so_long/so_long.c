/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:34:52 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/03 21:26:33 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char *map)
{
	game->mlx_ptr = mlx_init();
	game->img = img_init(game->mlx_ptr);
	read_map(map, game);
	//check_map addd
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->wid * 64, \
	game->hei * 64, "so_long");
	img_set(game);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_putstr_fd("Error! : argument is wrong\n", 1);
		exit(1);
	}
	game = malloc(sizeof(t_game));
	game_init(game, av[1]);
	mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
