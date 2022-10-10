/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:15:15 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/07 20:27:40 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - g->wid] == 'C')
		g->col_cnt++;
	if (g->str_line[i - g->wid] == 'E' && g->col_cnt == g->col_all)
		clear_game(g);
	else if (g->str_line[i - g->wid] != '1' && g->str_line[i - g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		img_set(g);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i - 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i - 1] == 'E' && g->col_cnt == g->col_all)
		clear_game(g);
	else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		img_set(g);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + g->wid] == 'C')
		g->col_cnt++;
	if (g->str_line[i + g->wid] == 'E' && g->col_cnt == g->col_all)
		clear_game(g);
	else if (g->str_line[i + g->wid] != '1' && g->str_line[i + g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->wid] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		img_set(g);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->str_line))
	{
		if (g->str_line[i] == 'P')
			break ;
	}
	if (g->str_line[i + 1] == 'C')
		g->col_cnt++;
	if (g->str_line[i + 1] == 'E' && g->col_cnt == g->col_all)
		clear_game(g);
	else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		img_set(g);
	}
}
