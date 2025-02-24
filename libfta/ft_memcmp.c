/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:03:17 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/15 12:15:05 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			i;

	m1 = (unsigned char *) s1 ;
	m2 = (unsigned char *) s2 ;
	i = 0;
	if (n == 0)
		return (i);
	while (m1[i] == m2[i] && i + 1 < n)
		i ++;
	return (m1[i] - m2[i]);
}
