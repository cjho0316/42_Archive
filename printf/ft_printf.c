/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:53:18 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/09 15:31:02 by jang-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_sig(va_list ap, char sig, int *len)
{
	if (sig == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (sig == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (sig == 'p')
		ft_print_mem_address(va_arg(ap, unsigned long long), len);
	else if (sig == 'd' || sig == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (sig == 'u')
		ft_unsigned_putnbr(va_arg(ap, unsigned int), len);
	else if (sig == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", len);
	else if (sig == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", len);
	else if (sig == '%')
		ft_putchar('%', len);
}

int	ft_parsing(va_list ap, char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			ft_check_sig(ap, str[i + 1], len);
			i++;
		}
		else
			ft_putchar(str[i], len);
		i++;
	}
	return (*len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	len = 0;
	ft_parsing(ap, (char *)str, &len);
	va_end(ap);
	return (len);
}
