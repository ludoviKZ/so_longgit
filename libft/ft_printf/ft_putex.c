/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:11:44 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/23 15:46:49 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putex(unsigned int n, int form)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret += (ft_putex((n / 16), form));
		ret += (ft_putex((n % 16), form));
	}
	else if (n < 10)
		ret += (ft_putnbr (n));
	else
	{
		if (form == 0)
			ret += (ft_putchar(n + 87));
		else
			ret += (ft_putchar(n + 55));
	}
	return (ret);
}
