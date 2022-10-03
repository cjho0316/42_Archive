/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:03:03 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/03 16:31:39 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = 0;
	while (*s)
	{
		if (*s == (const char)c)
			p = s;
		s++;
	}
	if (*s == (char)c)
		p = s;
	return ((char *)p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	idx;

	idx = 0;
	while ((s1[idx] != '\0' || s2[idx] != '\0') && idx < (unsigned char)n)
	{
		if ((unsigned char)s1[idx] == (unsigned char)s2[idx])
			idx++;
		else
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
	}
	return (0);
}

char	*ft_strddup(char *src)
{
	char	*new_mem;
	int		size;
	int		i;

	new_mem = NULL;
	size = ft_strlen(src);
	i = 0;
	new_mem = malloc(size + 1);
	if (!(new_mem))
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		new_mem[i] = src[i];
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}

int	ft_strllcpy(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_strjjoin(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	new_mem = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strddup(s2));
	else if (s2 == NULL)
		return (ft_strddup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = malloc(s1_len + s2_len);
	if (!(new_mem))
		return (NULL);
	ft_strllcpy(new_mem, s1, s1_len + 1);
	ft_strllcpy(new_mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new_mem);
}
