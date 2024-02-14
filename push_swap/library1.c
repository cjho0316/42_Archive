/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:21:51 by jang-cho          #+#    #+#             */
/*   Updated: 2022/12/31 14:25:08 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == 0 || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int	put_idx(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'\
		|| str[i] == '\n' || str[i] == '\v'\
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		i++;
		i *= -1;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

long long	ft_atoll(const char *str)
{
	long long	i;
	long long	n;
	long long	result;

	i = put_idx(str);
	n = 1;
	result = 0;
	if (!str)
		return (0);
	if (i < 0)
	{
		n = -1;
		i *= -1;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if ((result * n) >= 9223372036854775807)
		return (-1);
	else if ((result * n * -1) - 1 > 9223372036854775807)
		return (0);
	else
		return (result * n);
}

void	free_all(t_deque *q1)
{
	t_Node	*p;
	t_Node	*s;
	int		i;
	int		cnt;

	i = 0;
	p = q1->head;
	s = q1->head;
	cnt = q1->dqcnt;
	while (i < cnt)
	{
		p = s->next;
		free(s);
		s = p;
		i++;
	}
}
