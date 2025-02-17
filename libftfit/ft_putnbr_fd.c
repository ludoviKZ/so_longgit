/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:34:57 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/15 15:03:09 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = -147483648;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
	return ;
}
