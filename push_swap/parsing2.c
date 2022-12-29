/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 05:55:27 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 10:57:46 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

int	aligned_check(t_deque *q)
{
	int		i;
	int		j;
	int		k;
	int		total;
	t_Node	*p;

	i = 0;
	p = q->head;
	total = q->dqcnt - 1;
	while (i < total)
	{	
		j = p->data;
		k = p->next->data;
		if (j > k)
		{
			return (0);
		}
		p = p->next;
		i++;
	}
	return (1);
}

void	chk_avvalsorted(t_deque *a)
{
	if (aligned_check(a) || a->dqcnt == 0)
		exit(1);
}
