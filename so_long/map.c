/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:52:58 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/03 21:26:39 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *filename, t_game *g)
{
	char	*line;
	char	*str;
	int		fd;

	fd = open(filename, O_RDONLY);
	str = ft_strrchr(filename, '.');
	if (fd <= 0 || ft_strncmp(".ber", str, 4) != 0)
	{
		ft_putstr_fd("File isn't .ber file\n", 1);
		exit(1);
	}
	line = get_next_line(fd);
	g->wid = ft_strlen(line) - 1;
	g->hei = 0;
	g->walk_cnt = 0;
	g->str_line = ft_strddup(line);
	free(line);
	while (line)
	{
		g->hei++;
		line = get_next_line(fd);
		if (line)
			g->str_line = ft_strjjoin(g->str_line, line);
	}
	close(fd);
}
