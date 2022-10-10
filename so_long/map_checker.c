/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:55:11 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/10 20:00:13 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_msg(int e_cnt, int p_cnt, int col_all)
{
	if (e_cnt != 1)
	{
		printf("Error! : must contain a exit!");
		exit(1);
	}
	else if (p_cnt != 1)
	{
		printf("Error! : must contain a player!");
		exit(1);
	}
	else if (col_all < 1)
	{
		printf("Error! : must contain at least one collectable!");
		exit(1);
	}
}

void	print_surrounded_msg(void)
{
	printf("Map must be surrounded\n");
	exit(1);
}

void	is_surrounded(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->str_line))
	{
		if (i < game->wid)
		{
			if (game->str_line[i] != '1')
				print_surrounded_msg();
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid - 1)
		{
			if (game->str_line[i] != '1')
				print_surrounded_msg();
		}
		else if (i > (int)ft_strlen(game->str_line) - game->wid)
		{
			if (game->str_line[i] != '1')
				print_surrounded_msg();
		}
		i++;
	}
}

void	is_valid_param(t_game *game)
{
	int	i;
	int	e_cnt;
	int	p_cnt;

	i = 0;
	e_cnt = 0;
	p_cnt = 0;
	game->col_all = 0;
	game->col_cnt = 0;
	game->walk_cnt = 0;
	while (i < (int)ft_strlen(game->str_line))
	{
		if (game->str_line[i] != 'C' && game->str_line[i] != '1' && \
		game->str_line[i] != '0' && game->str_line[i] != 'P' && \
		game->str_line[i] != 'E')
			print_check_error_msg();
		if (game->str_line[i] == 'C')
			game->col_all++;
		else if (game->str_line[i] == 'P')
			p_cnt++;
		else if (game->str_line[i] == 'E')
			e_cnt++;
		i++;
	}
	print_error_msg(e_cnt, p_cnt, game->col_all);
}
