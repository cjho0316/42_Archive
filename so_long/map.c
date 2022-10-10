/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:52:58 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/10 20:00:15 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_check_error_msg(void)
{
	printf("Error! : fatal error! check file thoroughly\n");
	exit(1);
}

void	build_map_error(int fd, char *line, t_game *g)
{
	int	count;
	int	total;

	total = 0;
	count = 0;
	while (line)
	{
		line = get_next_line(fd);
		g->hei++;
		if (line)
		{
			count = ft_strlen(line) - 1;
			total += count;
			g->str_line = ft_strjjoin(g->str_line, line);
			if (count != g->wid && total >= ft_strlen(g->str_line) - g->wid)
				print_check_error_msg();
		}
	}
}

void	map_read(char *filename, t_game *g)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (fd <= 0 || line == 0)
		print_check_error_msg();
	g->wid = ft_strlen(line) - 1;
	g->hei = 0;
	g->str_line = ft_strddup(line);
	free(line);
	build_map_error(fd, line, g);
	close(fd);
}
