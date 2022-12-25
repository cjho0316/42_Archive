/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 05:55:27 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/26 04:42:50 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	aligned_check(t_deque *q)
{
	int	i;
	int	total;

	i = 0;
	total = q->dqcnt;
	while (i < total)
	{	
		if (q->head->data < q->head->next->data)
		{
			return (0);
		}
		q = q->head->next;
		i++;
	}
	return (1);
}