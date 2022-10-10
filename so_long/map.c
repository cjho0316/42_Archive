/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:52:58 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/10 18:53:02 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_check_error_msg(void)
{
	printf("Error! : fatal error! check file thoroughly\n");
	exit(1);
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
	while (line)
	{
		g->hei++;
		line = get_next_line(fd);
		printf("%s", line);
		if (line && g->wid != ft_strlen(line) - 1)
			print_check_error_msg();
		else
			g->str_line = ft_strjjoin(g->str_line, line);
	}
	close(fd);
}
