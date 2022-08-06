/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:46:51 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/06 17:07:16 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*afterline_word(char *p)
{
	int		idx;
	int		len;
	char	*arr;

	len = ft_strlen1(p);
	idx = ft_strchr_idx(p, '\n');
	if (!len || idx == -1)
		return (0);
	arr = (char *)malloc(sizeof(char) * (len - idx + 1));
	if (arr == 0)
		return (0);
	if (len > 0 && idx != -1)
	{
		ft_strlcpy1(arr, p + idx + 1, len - idx + 1);
		return (arr);
	}
	free (arr);
	return (0);
}

char	*firstline_word(char *p)
{
	int		idx;
	char	*arr;

	idx = ft_strchr_idx(p, '\n');
	if (p != 0 && idx != -1)
	{
		arr = (char *)malloc(sizeof(char) * (idx + 1 + 1 + 1));
		ft_strlcpy1(arr, p, idx + 1);
		arr[idx] = '\n';
		arr[idx + 1] = '\0';
		return (arr);
	}
	return (NULL);
}

char	*read_line(int fd, char *p)
{
	char			*str;
	int				tmp;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (0);
	tmp = 1;
	int ret = -1;
	while (tmp > 0 && ret == -1)
	{
		tmp = read(fd, str, BUFFER_SIZE);
		str[tmp] = '\0';
		if (tmp == -1)
		{
			free(str);
			return (NULL);
		}
		p = ft_strjoin1(p, str);
		ret = ft_strchr_idx(p, '\n');
	}
	free(str);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*p;
	char		*arr;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	p = read_line(fd, p);
	if (p == 0)
		return (NULL);
	arr = firstline_word(p);
	p = afterline_word(p);
	return (arr);
}

// #include <stdio.h>

// int main()
// {
// 	int fd = open("sample.txt", O_RDWR);
// 	char *str; 
	
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		i++;
// 	}
// 	return 0;
// }