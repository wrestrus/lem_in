/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:42:23 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 18:22:45 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;

	if (!s)
		return ;
	i = ft_strlen(s);
	while (i >= 0)
	{
		s[i] = '\0';
		i--;
	}
}
