/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:07:45 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/17 14:41:21 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_freearr(char **arr, int e)
{
	while (e > 0)
	{
		e--;
		free(arr[e]);
	}
	free(arr);
	return (0);
}

char	*ft_fill(char *arr, char const *s, int loc, int size)
{
	int	move;

	move = 0;
	while (move < size)
	{
		arr[move] = s[move + (loc - size)];
		move++;
	}
	arr[move] = '\0';
	return (arr);
}

char	**ft_alocate(char **arr, char const *s, unsigned int n, char c)
{
	unsigned int	pos;
	unsigned int	cont;
	unsigned int	size;

	pos = 0;
	cont = 0;
	while (cont < n)
	{
		size = 0;
		while (s[pos] == c && s[pos] != '\0')
			pos ++;
		while (s[pos] != c && s[pos] != '\0')
		{
			size++;
			pos ++;
		}
		arr[cont] = (char *)malloc(sizeof(char) * (size + 1));
		if (arr == NULL || arr[cont] == NULL)
			return (ft_freearr (arr, cont));
		ft_fill(arr[cont], s, pos, size);
		cont ++;
	}
	arr[cont] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	n;
	unsigned int	le;
	char			**split;

	n = 0;
	le = 0;
	while (s[le] != '\0')
	{
		if (s[le] == c)
			le++;
		else
		{
			n ++;
			while (s[le] != '\0' && s[le] != c)
				le++;
		}
	}
	split = (char **) malloc (sizeof (char *) * (n +1));
	if (split == NULL)
		return (0);
	if (ft_alocate (split, s, n, c) == NULL)
		return (0);
	return (split);
}
