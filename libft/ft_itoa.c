/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:33:40 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 21:12:42 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		len;
	char	*num;

	len = ft_numlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(num = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (ft_is_neg(n) > 0)
	{
		num[0] = '-';
		n = -n;
	}
	num[len] = '\0';
	len--;
	while (n != 0)
	{
		num[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}
