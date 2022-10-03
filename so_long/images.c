/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:59:20 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/03 21:33:50 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	src;
	int		wid;
	int		hei;

	src.tile_issac = mlx_xpm_file_to_image(mlx, "./images/tile_issac.xpm"\
	, &wid, &hei);
	src.tile_door = mlx_xpm_file_to_image(mlx, "./images/tile_door.xpm"\
	, &wid, &hei);
	src.tile = mlx_xpm_file_to_image(mlx, "./images/tile.xpm"\
	, &wid, &hei);
	src.tile_collectable = mlx_xpm_file_to_image(mlx, \
	"./images/tile_collectable.xpm", &wid, &hei);
	src.tile_obstacles = mlx_xpm_file_to_image(mlx, \
	"./images/tile_obstacles.xpm", &wid, &hei);
	return (src);
}

void	img_put(t_game *game, int w, int h)
{
	if (game->str_line[h * game->wid + w] == '1')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img.tile_obstacles, w * 64, h * 64);
	}
	else if (game->str_line[h * game->wid + w] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img.tile_collectable, w * 64, h * 64);
	}
	else if (game->str_line[h * game->wid + w] == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img.tile_issac, w * 64, h * 64);
	}
	else if (game->str_line[h * game->wid + w] == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img.tile_door, w * 64, h * 64);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img.tile, w * 64, h * 64);
	}
}

void	img_set(t_game *game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			img_put(game, wid, hei);
			wid++;
		}
		hei++;
	}
}
