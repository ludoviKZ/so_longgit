/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:10:28 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/16 11:40:59 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr( const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s[i] == (char)c)
		return ((char *)s);
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == (char) c)
			return ((char *)s + i);
	}
	return (0);
}
