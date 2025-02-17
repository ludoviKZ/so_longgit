/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:07:45 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/15 17:14:59 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	tot;
	char			*sub;
	int				strt;

	tot = ft_strlen (s);
	if (s == 0)
		return (0);
	if (start > tot)
		strt = 0;
	else if ((tot - start) < len)
		strt = tot - start;
	else
		strt = len;
	sub = (char *) malloc(sizeof(char) * (strt +1));
	if (sub == 0)
		return (0);
	if (strt == 0)
		*sub = '\0';
	else
		ft_strlcpy (sub, s + start, strt +1);
	return (sub);
}
