/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:07:15 by jang-cho          #+#    #+#             */
/*   Updated: 2022/07/13 20:33:37 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	put_idx(const char *str)
{
	int	i;

	i = 0;
	while (str[i] <= 32)
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

int	check_ovf(long result)
{
	if (result == 9223372036854775807)
		return (-1);
	else if (result == -9223372036854775809)
		return (0);
	else
		return (result);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	n;
	long	result;

	i = put_idx(str);
	n = 1;
	result = 0;
	if (i < 0)
	{
		n = -1;
		i *= -1;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += str[i] - '0';
		}
		else
			return (check(ovf(result * n)));
		i++;
	}
	return (check(ovf(result * n)));
}
