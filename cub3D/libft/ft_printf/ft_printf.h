/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:17:37 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/22 19:15:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *str, ...);
int		print_char(int c);
int		print_str(char *s);
int		print_hexa(unsigned int n, char c);
int		print_address(unsigned long long ptr);
int		print_demi(int n);
int		print_unsign(unsigned int n);
int		ft_strlen(const char *s);
int		ft_nbr_len(long long n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(long long n);
char	*ft_findchr(const char *s, int c);

#endif
