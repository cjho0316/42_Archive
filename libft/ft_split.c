/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:42:00 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/15 19:41:48 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cnt_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

void	ft_free(char **arr, size_t num)
{
	while (num)
	{
		free(arr[num]);
		num--;
	}
	free(arr);
	return ;
}

void	word_to_arr(char **arr, char const *str, char c)
{
	size_t	num;
	size_t	i;

	num = 0;
	i = 0;
	while (*str)
	{
		while (str[i] != 0 && str[i] == c)
			i++;
		while (str[i] != 0 && str[i] != c)
			i++;
		arr[num] = (char *)malloc(sizeof(char) * (i + 1));
		if (arr[num] == 0)
			return (ft_free(arr, num));
		ft_strlcpy(arr[num], str, i + 1);
		num ++;
		str += i;
	}
}

char	**ft_split(char const *str, char c)
{
	size_t		numbers;
	char		**arr;

	numbers = ft_cnt_word(str, c);
	arr = (char **)malloc(sizeof(char *) * (numbers + 1));
	if (arr == 0)
		return (0);
	arr[numbers] = 0;
	word_to_arr(arr, str, c);
	return (arr);
}
