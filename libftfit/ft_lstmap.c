/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:02:50 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/17 16:11:52 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iter;
	t_list	*ret;

	ret = NULL;
	if (lst == 0)
		return (0);
	if (f == NULL)
		return (0);
	while (lst != NULL)
	{
		iter = ft_lstnew(f(lst->content));
		if (iter == NULL)
		{
			ft_lstclear(&iter, (*del));
			ft_lstclear(&ret, (*del));
			return (NULL);
		}
		ft_lstadd_back (&ret, iter);
		lst = lst-> next;
	}
	return (ret);
}
