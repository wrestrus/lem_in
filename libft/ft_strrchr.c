/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:27:20 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 18:17:11 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s;

	s = NULL;
	while (*str)
	{
		if (*str == c)
			s = (char *)str;
		str++;
	}
	if (c == '\0')
		s = (char *)str;
	return (s);
}
