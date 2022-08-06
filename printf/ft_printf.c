/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jang-cho <jang-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:53:18 by jang-cho          #+#    #+#             */
/*   Updated: 2022/08/07 05:24:21 by jang-cho         ###   ########.fr       */
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
	ft_parsing(ap, (char *)str, &len);
	va_end(ap);
	return (len);
}


// #include <stdio.h>
// #include <limits.h>
// int	main()
// {
// 	printf(" %d\n", INT_MIN);
// }
// 	char s1[] = "hello";
// 	char s2[] = "world";
// 	void *p = s1;
// 	int num = -2147483648;
// 	int	num2 = (int)-15;
// 	int	num3 = -2147483647;
// 	int	n = 0;
// 	int n1 = 0;

// 	//printf("printf %%p: %p\n", p);
// 	printf("printf %%u: %u\n",0xa);
// 	ft_printf("printf %%u: %u\n",0xa);
// 	ft_printf("--------------------------------\n");
// 	printf("printf %%x: %x\n", 15);
// 	ft_printf("printf %%x: %x\n", 15);
// 	ft_printf("--------------------------------\n");
// 	printf("printf %%i: %i\n", -0xa);
// 	ft_printf("printf %%i: %i\n", -0xa);
// 	ft_printf("--------------------------------\n");
// 	printf("printf %%x: %x\n", -1);
// 	ft_printf("printf %%x: %x\n", -1);
// 	ft_printf("--------------------------------\n");
// 	printf("printf %%x: %x\n", -15);
// 	ft_printf("printf %%x: %x\n", -15);
// 	ft_printf("--------------------------------\n");
// 	printf("printf %%x: %x\n", -25);
// 	ft_printf("printf %%x: %x\n", -25);
// 	ft_printf("--------------------------------\n");
// 	printf("printf %%x: %x\n", 15);
// 	ft_printf("printf %%x: %x\n", 15);
// 	ft_printf("--------------------------------\n");
// 	printf("printf %%u: %u, %u , %u\n", num, num2, num3);
// 	ft_printf("printf %%u: %u, %u , %u\n", num, num2, num3);
// 	//printf("test:: %d %w\n", 1, 12);
// 	ft_printf("--------------------------------\n");
// 	ft_printf("ft_printf %%X: %X\n", num2);
// 	ft_printf("ft_printf %%x: %x\n", -1);
// 	ft_printf("ft_printf %%x: %x\n", -15);
// 	ft_printf("ft_printf %%x: %x\n", -25);
// 	ft_printf("ft_printf %%X: %X\n", 15);
// 	ft_printf("ft_printf %%u: %u, %u , %u\n", num, num2, num3);
// 	ft_printf("wow chin gu deul! %%  bbak bbak e ah jo ssi ya!\n");
// 	ft_printf("ft_printf %%d %d\n", 0xf);
// 	ft_printf("what you input: %c  %s  %s  %c %p\n ", 'b', s1, s2, 'z', p); 
// 	//ft_printf("test:: %d %w\n", 1, 12);
// 	n = ft_printf("again you input: %c yey! %s yay %s lololo %c\n", 'b', "'hello'", "'world'", 'z'); 
// 	n1 = ft_printf("djaskl%cdjasd%s\n", 'K', "hello");

// 	printf("%d\n", n);
// 	printf("%d\n", n1);
// 	return (0);
// }
