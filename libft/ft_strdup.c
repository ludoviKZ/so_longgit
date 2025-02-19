/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:07:45 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/17 11:49:41 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*clone;

	len = ft_strlen ((const char *)src);
	(clone = (char *) malloc(sizeof(char) * len + 1));
	if (clone == 0)
		return (0);
	len = 0;
	while (src[len] != '\0')
	{
		clone[len] = src[len];
		len++;
	}
	clone[len] = '\0';
	return (clone);
}
/*int		main(void)
{
	char	*str;
	char	*allocated;

	str = "Hello World with malloc()";
	printf("original  : base  : $%s$ @ %p\n", str, str);
	allocated = ft_strdup(str);
	printf("ft_copied : alloc : $%s$ @ %p\n", allocated, allocated);
}*/
