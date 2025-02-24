/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:02:50 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/16 15:45:43 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clon;

	if (lst == 0)
		return ;
	while (*lst != 0)
	{
		clon = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = clon;
	}
}
