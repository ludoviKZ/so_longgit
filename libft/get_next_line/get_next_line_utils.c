/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:14:07 by lzorzit           #+#    #+#             */
/*   Updated: 2024/10/27 17:53:30 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strchrgnx( const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s[i] == (char)c)
		return (1);
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == (char) c)
			return (1);
	}
	return (0);
}

int	ft_strlengnx(const char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

void	*ft_malloclen(size_t val1, size_t val2)
{
	char	*ret;
	size_t	bezero;

	bezero = 0;
	ret = malloc(val2 * val1);
	if (!ret)
		return (NULL);
	while (bezero < val1 * val2)
	{
		ret[bezero] = '\0';
		bezero++;
	}
	return (ret);
}

char	*ft_strjoingnx(char *s1, char *s2)
{
	int		prel;
	int		sufl;
	char	*full;
	int		n;

	sufl = ft_strlengnx (s2);
	prel = ft_strlengnx (s1);
	n = 0;
	full = malloc(sizeof(char) * (sufl + prel +1));
	if (full == 0 || s1 == 0 || s2 == 0)
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
	free (s1);
	return (full);
}
