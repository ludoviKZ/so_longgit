/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:02:50 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/17 10:51:49 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == 0)
		return ;
	if (lst == 0)
		return ;
	if (*lst != 0)
		ft_lstlast (*lst)->next = new;
	else
		*lst = new;
	return ;
}
