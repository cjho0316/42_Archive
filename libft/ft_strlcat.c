/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 08:27:21 by jangchoi          #+#    #+#             */
/*   Updated: 2022/07/06 19:30:28 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *len)
{
	int	i;

	i = 0;
	while (len[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	ssize;
	unsigned int	dsize;
	unsigned int	i;

	i = 0;
	ssize = ft_strlen(src);
	dsize = ft_strlen(dest);
	if (size == 0)
		return (size + ssize);
	else if (size <= dsize)
		return (size + ssize);
	else if (size > dsize)
	{
		while (dsize + i < size - 1 && src[i] != '\0')
		{
			dest[dsize + i] = src[i];
			i++;
		}
	}
	dest[dsize + i] = '\0';
	return (dsize + ssize);
}
