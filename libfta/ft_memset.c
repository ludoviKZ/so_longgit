/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:09:18 by lzorzit           #+#    #+#             */
/*   Updated: 2024/01/04 18:05:35 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cpy;
	size_t	count;

	count = 0;
	cpy = s;
	while (count < n)
	{
		*cpy = c;
		cpy ++;
		count ++;
	}
	return (s);
}
