/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 02:38:18 by bferdjan          #+#    #+#             */
/*   Updated: 2025/04/17 02:38:44 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

static void	ft_putstr(const char *s, int *len)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", len);
		return ;
	}
	i = 0;
	while (s[i])
		ft_putchar(s[i++], len);
}

static void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[++i] == 's')
				ft_putstr(va_arg(args, char *), &len);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr(va_arg(args, int), &len);
			else if (format[i] == 'c')
				ft_putchar(va_arg(args, int), &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
