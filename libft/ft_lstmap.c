/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:35:10 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 21:11:23 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*newlist;

	if (!lst || !f)
		return (NULL);
	newlist = f(lst);
	begin = newlist;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlist->next = f(lst)))
		{
			while (begin)
			{
				free(begin->content);
				free(begin);
				begin = begin->next;
			}
			return (NULL);
		}
		newlist = newlist->next;
	}
	return (begin);
}
