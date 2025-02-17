/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:16:13 by lzorzit           #+#    #+#             */
/*   Updated: 2024/01/04 16:24:15 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litl, size_t len)
{
	size_t	c;
	size_t	d;

	if (!big && !len)
		return (0);
	if (*litl == '\0')
		return ((char *)big);
	d = 0;
	c = 0;
	while (big[c] != '\0' && c < len)
	{
		if (big[c] == *litl)
		{
			d = c;
			while (big[d] == litl[(d - c)] && d < len)
			{
				d++;
				if (litl[(d - c)] == '\0')
					return ((char *)&big[c]);
			}
		}
		c++;
	}
	return (0);
}
