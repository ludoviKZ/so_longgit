/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:10:28 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/15 16:26:00 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	while (n != 0)
	{
		if (s [n] == (char)c)
			return ((char *)(s + n));
		n--;
	}
	if (s [n] == (char)c)
		return ((char *)(s + n));
	return (0);
}
