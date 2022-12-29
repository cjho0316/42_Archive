/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 05:55:27 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/29 15:14:23 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>

int	find_dup(t_deque	*dq, int num)
{
	t_Node	*s;

	s = dq->head;
	while (s != NULL)
	{
		if (s->data == num)
			return (1);
		s = s->next;
	}
	return (0);
}

int	integrity_check(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if ((str[i + 1] < '0' || str[i + 1] > '9') && str[i + 1] != ' ')
			{
				return (0);
			}
		}
		else if ((str[i] > 58 || str[i] < 47) && str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	arg2list(char *av, t_deque *dq)
{
	int			i;
	long long	k;
	char		**arr;

	i = 0;
	arr = ft_split(av, ' ');
	if (arr == NULL)
		return (0);
	while (arr[i] != NULL)
	{
		k = ft_atoll(arr[i]);
		if (k > INT_MAX || k < INT_MIN)
			p_error(1);
		if (find_dup(dq, k))
			p_error(1);
		else
			dqaddlast(dq, k);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (1);
}

int	argument_check(char *av)
{
	char	*str;
	int		i;

	str = av;
	i = 0;
	if (str[0] == '\0')
		p_error(1);
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	push_in_deque(int ac, char **av, t_deque *dq)
{
	int			i;
	long long	k;

	i = 1;
	if (ac == 1)
		exit(1);
	while (i < ac)
	{
		if (integrity_check(av[i]))
		{
			if (argument_check(av[i]))
				arg2list(av[i], dq);
			else
			{
				k = ft_atoll(av[i]);
				if (!find_dup(dq, k) && (k <= INT_MAX && k >= INT_MIN))
					dqaddlast(dq, k);
				else
					p_error(1);
			}
		}
		else
			p_error(1);
		i++;
	}
}
