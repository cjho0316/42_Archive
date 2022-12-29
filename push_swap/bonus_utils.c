/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:48:38 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 18:10:24 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

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
