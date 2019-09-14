/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:20:45 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 18:21:58 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	return ((void *)str);
}
