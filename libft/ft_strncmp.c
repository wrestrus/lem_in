/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:20:33 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 18:14:22 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)*s1 == (unsigned char)*s2 && i < n && *s1)
	{
		s1++;
		s2++;
		i++;
	}
	if ((!s1 && !s2) || i == n)
		return (0);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
