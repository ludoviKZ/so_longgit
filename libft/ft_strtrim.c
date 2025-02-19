/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:17:22 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/17 13:12:23 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_comp_end(char const *s1, char const *set)
{
	int	len;
	int	setp;

	setp = 0;
	len = ft_strlen (s1);
	while (len > 0)
	{
		while (s1[len] != set[setp] && set[setp] != '\0')
			setp ++;
		if (s1[len] != set[setp])
			return (len);
		len --;
		setp = 0;
	}
	return (0);
}

int	ft_comp_start(char const *s1, char const *set)
{
	int	len;
	int	setp;

	setp = 0;
	len = 0;
	while (s1[len] != '\0')
	{
		while (s1[len] != set[setp] && set[setp] != '\0')
			setp ++;
		if (s1[len] != set[setp])
			return (len);
		len ++;
		setp = 0;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL && set == NULL)
		return (0);
	end = ft_comp_end(s1, set);
	start = ft_comp_start(s1, set);
	if (start > end || *s1 == '\0')
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (0);
		*str = '\0';
		return (str);
	}
	str = (char *)malloc((end - start + 2) * sizeof(char));
	if (str == NULL)
		return (0);
	s1 += start;
	ft_strlcpy(str, (char *)s1, (end - start + 2));
	return (str);
}
