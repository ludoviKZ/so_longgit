/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:12:19 by lzorzit           #+#    #+#             */
/*   Updated: 2024/01/04 16:30:44 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*cpy;
	size_t	count;

	count = 0;
	cpy = s;
	while (count < n)
	{
		*cpy = 0;
		cpy ++;
		count ++;
	}
}
