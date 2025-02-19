/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:04:15 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/12 16:38:57 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	pos;

	pos = 0;
	if (*s == '\0')
		return ;
	while (s[pos] != '\0')
	{
		(*f)(pos, &s[pos]);
		pos ++;
	}
	return ;
}
