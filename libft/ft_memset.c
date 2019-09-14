/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:40:47 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 18:20:31 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int sym, size_t n)
{
	size_t			i;
	unsigned char	*newstr;

	i = 0;
	newstr = (unsigned char *)str;
	while (i < n)
	{
		newstr[i] = sym;
		i++;
	}
	return (str);
}
