/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:07:24 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/05 20:25:21 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_lst	*ft_listnew(char *content)
{
	t_lst *list;

	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	if (content == NULL)
		list->content = NULL;
	else
		list->content = ft_strdup(content);
	list->next = NULL;
	return (list);
}
