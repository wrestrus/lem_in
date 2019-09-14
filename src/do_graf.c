/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_graf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:32:29 by rgendry           #+#    #+#             */
/*   Updated: 2019/09/12 17:09:33 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void    dograf(t_lem *p)//char **str, int n, char **str1, int n1) // принимаем массив комнат и их количество
{
    t_flag  *fl;
    t_v     *hashtab[p->nodesize];
    // t_v     *node;

    fl = (t_flag*)malloc(sizeof(t_flag));
    fl->hash_nbr = p->nodesize;
    hashtab_init(hashtab, p->nodesize);
    fl->i = 0;
    while (fl->i < p->nodesize)
    {
        hashtab_add(hashtab, p->nodes[fl->i], fl->i, fl->hash_nbr);
        fl->i++;
    }
    // i = 0;
    // while(i < n)
    // {
    //     node = hashtab_lookup(hashtab, str[i], fl->hash_nbr);
    //     printf("Node: %s, %d\n", node->key, node->value);  //печать списка смежности
    //     i++;
    // }
    doconnect(hashtab, fl, p);//p->links, p->linksize);
}

void   copydominus(t_flag *fl, char *str)
{
    int i;

    i = 0;
    while (str[i] != '-')
    {
        fl->temp[i] = str[i];
        i++;
    }
    fl->temp[i] = '\0';
    i++;
    fl->c = i;
}

void   copyposleminus(t_flag *fl, char *str)
{
    int i;

    i = 0;
    while(str[fl->c] != '\0')
    {
        fl->temp1[i] = str[fl->c];
        fl->c++;
        i++;
    }
    fl->temp1[i] = '\0';
}

void    list_with_connect(t_v *node,  t_v *node1)
{
    t_connection *tt;
    t_connection *ptr;

    tt = (t_connection*)malloc(sizeof(t_connection));
    if(node->knot == NULL)
    {
        node->knot = tt;
        tt->bonds = node1;
        tt->next = NULL;
        tt->vizit = 0;
    }
    else
    {
        ptr = node->knot;
         while(ptr->next)
            ptr = ptr->next;
        tt->bonds = node1;
        tt->vizit = 0;
        tt->next = NULL;
        ptr->next = tt;
    }
}

void   doconnect(t_v **hashtab, t_flag *fl, t_lem *p)//char  **str1, int n1)
{
    t_v *node;
    t_v *node1;
    fl->p = -1;
    fl->k = 0;
    while(++fl->p < p->linksize)
    {
        ft_bzero(fl->temp, 10);
        ft_bzero(fl->temp1, 10);
        copydominus(fl,p->links[fl->p]);
        copyposleminus(fl, p->links[fl->p]);
        node = hashtab_lookup(hashtab, fl->temp, fl->hash_nbr);
        node1 = hashtab_lookup(hashtab, fl->temp1, fl->hash_nbr);
        if(node == NULL || node1 == NULL)
        {
            ft_putstr("no room in connect two V \n");
            exit(0);
        }
        list_with_connect(node,node1);
        list_with_connect(node1,node);
        fl->k = 0;
    }
    fl->ants = p->ants;

    ft_multyway(hashtab,p->start, p->end, fl);
}
