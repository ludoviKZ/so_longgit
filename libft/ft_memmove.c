/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:18:56 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/12 16:23:54 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			siz;
	size_t			inv;
	unsigned char	*d;
	unsigned char	*s;

	inv = 2;
	siz = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == (0) && s == (0))
		return (0);
	if (d > s)
	{
		inv = 0;
		d += n - 1;
		s += n - 1;
	}
	while (siz < n)
	{
		*d = *s;
		d += (-1 + inv);
		s += (-1 + inv);
		siz++;
	}
	return (dest);
}
