/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:49:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/03/09 18:04:09 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int res;
	int neg;

	res = 0;
	neg = 1;
	while (*str == ' ' || *str == '\0' || *str == '\t' || *str == '\f'
			|| *str == '\n' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * neg);
}
