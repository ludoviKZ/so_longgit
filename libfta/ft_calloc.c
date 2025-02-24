/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:24:14 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/15 16:41:48 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	tot;

	tot = (nmemb * size);
	arr = (void *) malloc (tot);
	if (arr == 0)
		return (0);
	ft_bzero (arr, tot);
	return (arr);
}
