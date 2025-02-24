/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbruns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:11:36 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/23 17:20:35 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbruns(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n > 9)
	{
		ret += (ft_putnbr((n / 10)));
		ret += (ft_putchar((n % 10) + 48));
	}
	else
		ret += (ft_putchar(n + 48));
	return (ret);
}
