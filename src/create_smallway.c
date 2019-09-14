/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_smallway.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:45:51 by blomo             #+#    #+#             */
/*   Updated: 2019/09/12 17:15:03 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_way  *create_smallway(t_way *ochered, char *str)
{
    t_way *way;
    t_way *temp;
    t_way *tempway;

    way = (t_way*)malloc(sizeof(t_way));
    while(ochered->next)
    {
        if(!ft_strcmp(ochered->sosed->key,str))
            break;
        ochered = ochered->next;
    }
    way->sosed = ochered->sosed;
    way->next = NULL;
    while(ochered->revnext)
    {
        tempway = (t_way*)malloc(sizeof(t_way));
        temp = ochered;
        while(ochered->sosed != temp->prev && ochered->revnext != NULL)
            ochered = ochered->revnext;
        tempway->sosed = ochered->sosed;
        tempway->next = way;
        way->revnext = tempway;
        way = tempway;
        if(ochered->revnext == NULL)
            break;
    }
    return(way);
}

void    close_way(t_way *way)
{
    t_way *temp;
    t_connection *temp1;
    temp = way;
    while(temp->next)
    {
        temp1 = temp->sosed->knot;
        while(temp1->bonds != temp->next->sosed && temp1 != NULL && temp1->next != NULL)
            temp1 = temp1->next;
        if(temp1 != NULL)
            temp1->vizit = 1;
        if(temp != NULL)
            temp = temp->next;
    }
    temp = way;
    if(temp)
    {
        if(temp->next != NULL)
            temp = temp->next;
        while(temp->next)
        {
            if(temp->sosed->vizit == 1)
                temp->sosed->vizit = 2;
            if (temp->sosed->vizit == 0)
                 temp->sosed->vizit = 1;
            temp = temp->next;
        }
        // temp->sosed->vizit = 0;
    }
}

void poisk_vershin1(t_way **temp, t_v *node)
{
    *temp = (t_way*)malloc(sizeof(t_way));
    (*temp)->sosed = node;
    (*temp)->next = NULL;
    (*temp)->revnext = NULL;
    node->smezh_rebro = 1;
}

void poisk_vershin2(t_way **temp, t_v *node)
{
    t_way *temp1;

    temp1 = (t_way*)malloc(sizeof(t_way));
    temp1->sosed = node;
    temp1->next = *temp;
    (*temp)->revnext = temp1;
    (*temp) = temp1;
    node->smezh_rebro = 1;
}

void poisk_vershin3(t_way **temp, t_v *hashtab2)
{
    *temp = (t_way*)malloc(sizeof(t_way));
    (*temp)->sosed = hashtab2->next;
    hashtab2->next->smezh_rebro = 1;
    (*temp)->next = NULL;
    (*temp)->revnext = NULL;
}

void poisk_vershin4(t_way **temp, t_v *hashtab2)
{
    t_way *temp1;

    temp1 = (t_way*)malloc(sizeof(t_way));
    temp1->sosed = hashtab2->next;
    hashtab2->next->smezh_rebro = 1;
    temp1->next = *temp;
    (*temp)->revnext = temp1;
    (*temp) = temp1;
}



t_way *poisk_vershin_s_indeksom_2(t_v **hashtab,t_flag *fl)
{
    t_way *temp;
    t_v **hashtab1;
    t_v *hashtab2;
    int i;

    temp = NULL;
    i = 0;
    hashtab1 = hashtab;
    while(i < fl->hash_nbr)
    {
        if(hashtab1[i])
        {
            if(hashtab1[i]->vizit == 2)
            {
                if(temp == NULL)
                    poisk_vershin1(&temp, hashtab1[i]);
                else
                    poisk_vershin2(&temp, hashtab1[i]);
            }
            hashtab2 = hashtab1[i];
            while(hashtab2->next != NULL)
            {
                if(hashtab2->next->vizit == 2)
                {
                    if(temp == NULL)
                         poisk_vershin3(&temp, hashtab2);
                    else
                        poisk_vershin4(&temp, hashtab2);
                }
                hashtab2 = hashtab2->next;
            }
        }
        i++;
    }
    return(temp);
}

void    open_way_2(t_way *way)
{
    t_way *temp;
    t_connection *temp1;

    temp = way;
    while(temp->next)
    {
        temp1 = temp->sosed->knot;
        while(temp1->bonds != temp->next->sosed && temp1 != NULL && temp1->next != NULL)
            temp1 = temp1->next;
        if(temp1 != NULL)
        {
            temp1->vizit = 0;
        }
        if(temp != NULL)
            temp = temp->next;
    }
    temp = way;
    if(temp)
    {
        if(temp->next != NULL)
            temp = temp->next;
        while(temp->next)
        {
            temp->sosed->vizit = 0;

            temp->sosed->is_node_one = 0;
            temp = temp->next;
        }
    }
}





void    open_way(t_allway *map)
{
    t_allway *temp;
    temp = map;
    while(temp)
    {
        open_way_2(temp->go);
        temp = temp->next;
    }
}



void close_rebra(t_way *rebra)
{
    t_way *temp;
    t_way *temp1;
    t_connection *connect;
    temp = rebra;
    while(temp)
    {
        connect = temp->sosed->knot;
        while(connect)
        {
            temp1 = rebra;
            while(temp1)
            {
                if(connect->bonds == temp1->sosed)
                {
                    connect->vizit = 1;
                }
            temp1 = temp1->next;
            }
            connect = connect->next;
        }
        temp = temp->next;
    }
}
