/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:44:55 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/12 16:50:06 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			c;
	unsigned char	*d;
	unsigned char	*s;

	c = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == (0) && s == (0))
		return (0);
	if (d == s)
		return (dest);
	while (c < n)
	{
		*d = *s;
		d++;
		s++;
		c++;
	}
	return (dest);
}
