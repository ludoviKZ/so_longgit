/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:50:13 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/12 16:49:39 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	pos;

	pos = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[pos] != '\0' && size > 1)
	{
		*dst = src[pos];
		dst++;
		pos++;
		size --;
	}
	*dst = '\0';
	return (ft_strlen(src));
}
