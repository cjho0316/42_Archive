/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:44:38 by jang-cho          #+#    #+#             */
/*   Updated: 2022/11/25 23:05:17 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// 받아온 인자에 대해서 정렬을 수행한다. -> algorithmns
// 인자를 파싱시켜주는 작업해야함.. 인자에 있는 요소들 받아서 배열로 가져다주기 
#include <stdio.h>
#include "deque.h"

void	p_error(int i)
{
	ft_putstr_fd("Error", i);
	exit(1);
}

int	main(int ac, char **av)
{
	t_deque	*deq1;
	t_deque	*deq2;


	deq1 = malloc(sizeof(t_deque));
	deq2 = malloc(sizeof(t_deque));
	dequeinit(deq1);
	dequeinit(deq2);

	//parsing
	push_in_deque(ac, av, deq1);

	// switch

	// algorithmns

	free(deq1);
	free(deq2);
}
