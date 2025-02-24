/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:34:57 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/17 11:35:54 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	size;

	size = 0;
	if (s == 0)
		return ;
	while (s[size] != '\0')
	{
		ft_putchar_fd(s[size], fd);
		size ++;
	}
}
