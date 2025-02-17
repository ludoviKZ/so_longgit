/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:54:32 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/17 13:32:55 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nod;

	nod = (t_list *)malloc(sizeof(t_list));
	if (nod == NULL)
		return (NULL);
	nod->content = content;
	nod->next = NULL;
	return (nod);
}
