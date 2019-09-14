/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:01:19 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 18:20:10 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*newstr;

	i = 0;
	newstr = (unsigned char *)str;
	while (i < n)
	{
		newstr[i] = '\0';
		i++;
	}
}
