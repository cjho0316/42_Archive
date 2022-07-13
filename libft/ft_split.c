/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:42:00 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/12 15:48:37 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *str, char c)
{
	size_t	num;

	num = 0;
	while (*str)
	{
		if (*str == c)
			num++;
		str++;
	}
	num += ft_strlen(str);
	return (num);
}

void	ft_strncpy(char	*dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void	word_to_arr(char **arr, char const *str, char c)
{
	size_t	num;
	size_t	i;

	num = 0;
	while (*str)
	{
		if (*str == c)
		{
			i++;
			str++;
		}
		else
		{
			i = 0;
			while (str[i] != c)
				i++;
			arr[num] = (char *)malloc(sizeof(char) * (i + 1));
			ft_strncpy(arr[num], str, i);
			num ++;
			str += i;
		}
	}
}

char	**ft_split(char const *str, char c)
{
	size_t		numbers;
	char		**arr;

	numbers = count_word(str, c);
	arr = (char **)malloc(sizeof(char *) * (numbers + 1));
	if (arr == 0)
		return (0);
	arr[numbers] = 0;
	word_to_arr(arr, str, c);
	return (arr);
}
