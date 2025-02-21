/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:05:54 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/24 10:39:09 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	size;

	size = 0;
	if (s == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[size] != '\0')
	{
		write(1, &s[size], 1);
		size ++;
	}
	return (size);
}

int	sort(va_list arg, const char par)
{
	int	ret;

	ret = 0;
	if (par == 'c')
		ret += (ft_putchar (va_arg (arg, int)));
	else if (par == 's')
		ret += (ft_putstr (va_arg (arg, char *)));
	else if (par == 'p')
		ret += (ft_putpoint (va_arg (arg, uintptr_t)));
	else if (par == 'd')
		ret += (ft_putnbr (va_arg (arg, int)));
	else if (par == 'i')
		ret += (ft_putnbr (va_arg (arg, int)));
	else if (par == 'u')
		ret += (ft_putnbruns (va_arg (arg, unsigned int)));
	else if (par == 'x')
		ret += (ft_putex (va_arg (arg, unsigned int), 0));
	else if (par == 'X')
		ret += (ft_putex (va_arg (arg, unsigned int), 1));
	else if (par == '%')
		ret += (ft_putchar('%'));
	return (ret);
}

int	ft_printf(const char *par, ...)
{
	va_list	arg;
	int		ret;
	int		i;

	ret = 0;
	va_start (arg, par);
	i = 0;
	if (par == 0)
		return (-1);
	while (par[i] != '\0')
	{
		if (par[i] == '%')
		{
			ret += (sort (arg, par[i +1]));
			i ++;
		}
		else
			ret += (ft_putchar(par[i]));
		i ++;
	}
	return (ret);
}
