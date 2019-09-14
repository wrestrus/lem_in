/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <rgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 12:50:47 by rgendry           #+#    #+#             */
/*   Updated: 2018/12/20 18:28:17 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(char const *s, char c)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (*s != '\0')
	{
		if (*s == c && i == 1)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}
