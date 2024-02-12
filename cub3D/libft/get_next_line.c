/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 21:33:57 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/22 19:18:40 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char	*read_and_save(int fd, char *buffer, char *save)
{
	char	*temp;
	int		bytes;

	while (save && !ft_strchr(save, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(save);
			return (NULL);
		}
		else if (bytes == 0)
			return (save);
		buffer[bytes] = '\0';
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (save);
}

static char	*get_line(char *save)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!save || !*save)
		return (NULL);
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	line = ft_substr(save, 0, i);
	return (line);
}

static char	*get_new_save(char *save)
{
	char	*new_save;
	size_t	i;

	i = 0;
	while (save && save[i] != '\n' && save[i])
		i++;
	if (save && save[i] == '\n')
		new_save = ft_strdup(&save[i + 1]);
	else
		new_save = NULL;
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	save[fd] = read_and_save(fd, buffer, save[fd]);
	line = get_line(save[fd]);
	save[fd] = get_new_save(save[fd]);
	free(buffer);
	return (line);
}
