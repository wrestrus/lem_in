/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:20:13 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 18:20:48 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str1;
	size_t			i;

	str1 = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (str1[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
