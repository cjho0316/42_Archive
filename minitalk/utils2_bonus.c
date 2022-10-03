/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:24:35 by jang-cho          #+#    #+#             */
/*   Updated: 2022/10/03 14:38:06 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0 || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*p;
	size_t		len1;
	size_t		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc(len1 + len2 + 1);
	if (p == 0)
		return (0);
	ft_strlcpy(p, s1, len1 + 1);
	ft_strlcat(p + len1, s2, len2 + 1);
	return (p);
}

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	int	dest_len;
	int	src_len;
	int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (len <= dest_len)
		return (src_len + len);
	while (*dest && i++ < len)
		dest++;
	while (*src && i < len - 1)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (dest_len + src_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
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
	while (i < len - 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
