/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:07:45 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/15 13:01:08 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		prel;
	int		sufl;
	char	*full;
	int		n;

	sufl = ft_strlen (s2);
	prel = ft_strlen (s1);
	n = 0;
	full = (char *) malloc(sizeof(char) * (sufl + prel) + 1);
	if (full == 0)
		return (0);
	while (n < prel)
	{
		full[n] = s1[n];
		n++;
	}
	n = 0;
	while (n < sufl)
	{
		full[prel + n] = s2[n];
		n++;
	}
	full[sufl + prel] = '\0';
	return (full);
}
