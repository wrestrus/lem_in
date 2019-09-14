/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:23:02 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 21:09:09 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		words;
	char	**arr;

	i = 0;
	if (!c || !s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(arr = (char **)malloc(sizeof(*arr) * words + 1)))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		while (*s != c && words--)
		{
			arr[i] = ft_strsub(s, 0, ft_count_len((char const *)s, c));
			if (arr[i] == NULL)
				return (ft_free(arr, i));
			s = s + ft_count_len(s, c);
			i++;
		}
	}
	arr[i] = 0;
	return (arr);
}
