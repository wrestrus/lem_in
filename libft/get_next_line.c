/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:13:18 by rgendry           #+#    #+#             */
/*   Updated: 2019/04/05 18:59:17 by rgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_len(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		if (str[n] == '\n')
			return (n);
		n++;
	}
	return (-1);
}

int	get(int fd, char **arr, char **line, char *temp)
{
	int i;

	i = line_len(arr[fd]);
	if (i == -1)
		return (get_next_line(fd, line));
	else
	{
		*line = ft_strsub(arr[fd], 0, i);
		temp = ft_strdup(arr[fd] + i + 1);
		free(arr[fd]);
		arr[fd] = temp;
		if (!arr[fd][0])
			ft_strdel(&arr[fd]);
		return (1);
	}
}

int	file_end(int fd, char **arr, char **line, char *temp)
{
	if (ft_strchr(arr[fd], '\n'))
		return (get(fd, arr, line, temp));
	*line = ft_strdup(arr[fd]);
	ft_strdel(&arr[fd]);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*arr[1];
	char		*temp;
	int			n;

	if (!line)
		return (-1);
	n = read(fd, buff, BUFF_SIZE);
	if (n == 0 && arr[fd])
	{
		temp = NULL;
		return (file_end(fd, arr, line, temp));
	}
	if (n > 0)
	{
		buff[n] = '\0';
		if (!arr[fd])
			arr[fd] = ft_strnew(1);
		temp = ft_strjoin(arr[fd], buff);
		free(arr[fd]);
		arr[fd] = temp;
		return (get(fd, arr, line, temp));
	}
	return (n);
}
