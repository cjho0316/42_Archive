/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:48:38 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 13:24:46 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	compare_command(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (*(str1 + i) && *(str1 + i) == *(str2 + i))
		i++;
	return (*((unsigned char *)str1 + i) - *((unsigned char *)str2 + i));
}
