/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:34:52 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/10 18:36:55 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char *map)
{
	game->mlx_ptr = mlx_init();
	game->img = img_init(game->mlx_ptr);
	map_read(map, game);
	is_valid_param(game);
	is_surrounded(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->wid * 64, \
	game->hei * 64, "so_long");
	img_set(game);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

int	clear_game(t_game *game)
{
	game->walk_cnt++;
	printf("%s %d%s\n", "Clear! You have", game->walk_cnt, "steps.");
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
	char	*str;

	if (ac != 2)
	{
		printf("Error! : argument input error\n");
		exit(1);
	}
	str = ft_strrchr(av[1], '.');
	if (ft_strncmp(".ber", str, 4) != 0)
	{
		printf("Error! : File isn't .ber file\n");
		exit(1);
	}
	game = malloc(sizeof(t_game));
	game_init(game, av[1]);
	mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
