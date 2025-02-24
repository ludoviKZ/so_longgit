/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:11:28 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/23 17:03:04 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_countpnt(unsigned long n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += (ft_countpnt(n / 16));
		ret += (ft_countpnt(n % 16));
	}
	else
	{
		if (n < 10)
			ret += (ft_putnbr (n));
		else
			ret += (ft_putchar((n + 87)));
	}
	return (ret);
}

int	ft_putpoint(uintptr_t i)
{
	int	ret;

	ret = 0;
	if (i == 0)
		return (write (1, "(nil)", 5));
	ret += (write(1, "0x", 2));
	ret += ft_countpnt (i);
	return (ret);
}
