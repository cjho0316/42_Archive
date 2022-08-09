/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:46:51 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/10 03:02:22 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*afterline_word(char *save)
{
	char	*remains;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	len = ft_strlen(save);
	remains = (char *) malloc(sizeof(char) * (len - i + 1));
	if (!remains)
		return (NULL);
	j = 0;
	while (save[i])
		remains[j++] = save[i++];
	remains[j] = '\0';
	free(save);
	return (remains);
}

char	*firstline_word(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = (char *) malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *save)
{
	char	*buff;
	int		read_idx;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_idx = 1;
	while (!is_newline(save) && read_idx != 0)
	{
		read_idx = read(fd, buff, BUFFER_SIZE);
		if (read_idx == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_idx] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_line(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = firstline_word(save[fd]);
	save[fd] = afterline_word(save[fd]);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("sample.txt", O_RDWR);
// 	char *str; 
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s\n", str);
// 		i++;
// 	}
// 	return 0;
// }