/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:20:14 by jang-cho          #+#    #+#             */
/*   Updated: 2023/01/06 09:41:58 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cnt_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
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

char	*make_word(char *word, char const *s, int end, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		word[i] = s[end - len--];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free(int i, char **ptr)
{
	while (i-- > 0)
		free(ptr[i]);
	free(ptr);
	return ((void) NULL);
}

void	word_to_arr(char **ptr, char const *s, char c, int word_num)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (s[j] != '\0' && i < word_num)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			len++;
		}
		ptr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (ptr[i] == 0)
			ft_free(i, ptr);
		make_word(ptr[i], s, j, len);
		len = 0;
		i++;
	}
	ptr[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**ptr;

	word_num = cnt_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (ptr == 0)
		return (0);
	word_to_arr(ptr, s, c, word_num);
	return (ptr);
}
