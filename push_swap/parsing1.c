/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 05:55:27 by jang-cho          #+#    #+#             */
/*   Updated: 2022/11/26 00:09:02 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 에러 판별
// 1. 잘못된 인자 들어갔을 때
// 2. 중복된 값
// ------------------------
// 4. 잘못된형식(non instruction)
// 5. 잘못된형식(no)
// 인자로 들어가는 값들에대해 핸들링해주기
// --------------------------------
// 3. int형 범위를 벗어날 때 체크하는 함수만들기 -> 배열에담아주고 체크하기
// 6. duplicate되어있는 숫자를 찾아내는 함수만들기

#include "deque.h"
#include <stdio.h> //debug

int	find_duplicate(t_deque *p, int num)
{
	t_deque	*s;

	s = p;
	while (p->head != NULL)
	{
		if (p->head->data == num)
			return (1);
		s->tail = s->tail->next;
	}
	return (0);
}

int	integrity_check(char *av, int num)
{
	int	i;

	i = num;
	if (av[i] == '+' || av[i] == '-')
	{
		if ((av[i + 1] < '0' || av[i + 1] > '9') && av[i + 1] != ' ')
			p_error(1);
	}
	else if (av[i] > '9' || av[i] < '0')
		p_error(1);
	i++;
	return (1);
}

// convert argument into integer list
int	arg2list(char *av, t_deque *dq)
{
	int			i;
	long long	k;
	char		**arr;

	i = 0;
	arr = ft_split(av, ' ');
	printf("split array is : %s\n", *arr);
	if (arr == NULL)
		return (0);
	while (arr[i])
	{
		k = ft_atoll(arr[i]);
		if (k > INT_MAX || find_duplicate(dq, k))
		{
			p_error(1);
		}
		else
			dqaddlast(dq, k);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}

// 인자로 들어온 배열이 "1 2 3" 형태로 있는지 판별하는 함수
int	argument_check(char *av)
{
	char	*str;

	str = av;
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

// 만약 " " 형태의 quotation을 만나게된다면 펑션arg2list 콜해서 deque에 넣기
// 그렇지않다면 deque에 그냥 저장하기
void	push_in_deque(int ac, char **av, t_deque *dq)
{
	int		i;

	i = 1;
	if (ac == 1)
		p_error(1);
	while (i < ac)
	{
		if (integrity_check(av[i], i))
		{
			if (argument_check(av[i]))
				arg2list(av[i], dq);
			else
				dqaddlast(dq, ft_atoll(av[i]));
		}
		i++;
	}
}
