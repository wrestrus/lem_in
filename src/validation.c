/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:43 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/12 17:53:09 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		printerr(int t)
{
	if (t == 1)
		ft_putstr("Error: wrong number of ants.\n");
	if (t == 2)
		ft_putstr("Error: invalid name of a node.\n");
	if (t == 3)
		ft_putstr("Error: wrong number of start commands.\n");
	if (t == 4)
		ft_putstr("Error: wrong number of end commands.\n");
	return (0);
}

int		check_room(char *room)
{
	int i;

	i = 0;
	if (room[0] == 'L')
		return (0);
	while (room[i - 1] != ' ')
		i++;
	while (room[i] >= '0' && room[i] <= '9')
		i++;
	if (room[i] == ' ')
		i++;
	while (room[i] >= '0' && room[i] <= '9')
		i++;
	if (room[i] == '\0')
		return (1);
	return (0);
}

void	printarr(t_lem *p)
{
	int i;

	i = 0;
	printf("%s\n", "LINKS");
	while (i < p->linksize)
	{
		printf("%s\n", p->links[i]);
		i++;
	}
	i = 0;
	printf("%s\n", "NODES");
	while (i < p->nodesize)
	{
		printf("%s\n", p->nodes[i]);
		i++;
	}
	printf("ANTS: %d\n", p->ants);
	printf("START: %s\n", p->start);
	printf("END: %s\n", p->end);
}

int		makemaps(t_info *h, t_lem *p)
{
	int i;
	int flag;
	int j;

	i = 0;
	j = 0;
	flag = 0;
	h->lst = h->head;
	p->ants = ft_atoi(h->lst->content);
	if (ft_strcmp(ft_itoa(p->ants), h->lst->content) || p->ants < 1)
		return (printerr(1));
	h->lst = h->lst->next;
	p->links = (char **)malloc(sizeof(char*) * p->linksize);
	p->nodes = (char **)malloc(sizeof(char*) * p->nodesize);
	while (h->lst)
	{
		if (!ft_strcmp(h->lst->content, "##start"))
		{
			if (p->start != NULL)
				return (printerr(3));
			flag = 1;
			h->lst = h->lst->next;
		}
		if (!ft_strcmp(h->lst->content, "##end"))
		{
			if (p->end != NULL)
				return (printerr(4));
			flag = 2;
			h->lst = h->lst->next;
		}
		if (ft_strchr(h->lst->content, ' '))
		{
			if (!check_room(h->lst->content))
				return (printerr(2));
			if (flag == 1 && !p->start)
				p->start = ft_strndup(h->lst->content, ' ');
			if (flag == 2 && !p->end)
				p->end = ft_strndup(h->lst->content, ' ');
			p->nodes[i] = ft_strndup(h->lst->content, ' ');
			i++;
		}
		if (ft_strchr(h->lst->content, '-'))
		{
			p->links[j] = ft_strdup(h->lst->content);
			j++;
		}
		h->lst = h->lst->next;
	}
	printarr(p);
	return (1);
}

// void	printlist(t_lst *head)
// {
// 	while (head)
// 	{
// 		printf("%s\n", head->content);
// 		head = head->next;
// 	}
// }

int		validation(t_lem *p)
{
	t_info	h;
	char	*line;

	h.size = 0;
	while (get_next_line(0, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
		if (!h.size && line[0] != '#')
		{
			h.lst = ft_listnew(line);
			h.head = h.lst;
			h.size++;
		}
		else if (line[0] != '#' || !ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		{
			if (ft_strchr(line, ' '))
				p->nodesize++;
			if (ft_strchr(line, '-'))
				p->linksize++;
			h.lst->next = (ft_listnew(line));
			h.lst = h.lst->next;
			h.size++;
		}
	}
	h.lst = h.head;
	return (makemaps(&h, p));
}
