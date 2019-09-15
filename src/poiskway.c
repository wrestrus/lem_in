/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poiskway.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:46:35 by blomo             #+#    #+#             */
/*   Updated: 2019/09/15 21:28:34 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void one_of_map(t_allway **map, t_way *temp1)
{
    *map = (t_allway*)malloc(sizeof(t_allway));
    (*map)->go = temp1;
    (*map)->next = NULL;
    (*map)->prev = NULL;
}

void more_of_map(t_allway **map, t_way *temp1)
{
    t_allway  *map1;

    map1 = (t_allway*)malloc(sizeof(t_allway));
    map1->go = temp1;
    map1->next = *map;
    (*map)->prev = map1;
    *map = map1;
}

t_allway *create_map(t_v **hashtab, char *start, char *end,t_flag *fl)
{
    t_allway  *map;
    t_way *temp;
    t_way *temp1;
    t_way *temp2;
    map = NULL;
    fl->k = 1;
    while(fl->c)
    {
        temp  = ft_way(hashtab,start, end, fl);

        if(fl->c)
        {
            temp1 = create_smallway(temp,end);
            temp2= temp1;
            while(temp2)
                temp2 = temp2->next;
            close_way(temp1);
        }
        if(map == NULL)
        {
            if(fl->c)
                one_of_map(&map ,temp1);
        }
        else
        {
            if(fl->c)
                more_of_map(&map, temp1);
        }
    }


    return(map);
}

void del_hash(t_v **hashtab,int i)
{
    int c;
    t_v *temp;
    t_v *temp1;
    t_connection *tt;
    t_connection *tt1;
    c = 0;
    while(c < i)
    {
        temp = hashtab[c];
        while(temp)
        {
            tt = temp->knot;
            while(tt)
            {
                tt1 = tt->next;
                free(tt);
                tt = tt1;
            }
            temp1 = temp->next;
            free(temp);
            temp = temp1;
        }
        hashtab[c] = NULL;
        c++;
    }
}

void del_map(t_allway **map)
{
    t_allway *temp;
    t_allway *temp3;
    t_way *temp1;
    t_way *temp2;
    while(*map)
    {
        temp1 = (*map)->go;
        temp3 = (*map)->next;
        while(temp1)
        {
            temp2 = temp1->next;
            free(temp1);
            temp1 = temp2;
        }
        free(*map);
        *map = temp3;
    }
}

void  ft_multyway(t_v **hashtab, char *start, char *end,t_flag *fl)
{
    t_allway  *map;
    t_allway *map2;
    t_way *rebra;
    int z;
    z = 0;
    t_way *rebra1;
    t_way *temp;
    t_way *temp1;
    int i;
    map2 = (t_allway*)malloc(sizeof(t_allway));

    temp  = ft_way(hashtab,start, end, fl);
    temp1 = create_smallway(temp,end);
    map2->go = temp1;
    map2->next = NULL;
    open_way(map2);

    fl->c = 1;
    fl->poisk = 0;
    map = create_map(hashtab, start, end, fl);
    rebra = poisk_vershin_s_indeksom_2(hashtab,fl);
    rebra1 = rebra;
    while(rebra)
    {
        z++;
        rebra = rebra->next;
    }
    if(z>5)
    {
        fl->poisk = -1;
        open_way(map);
    }
    else
    {
         open_way(map);
         close_rebra(rebra);
    }

    map = NULL;
    fl->c = 1;
    map = create_map(hashtab, start, end, fl);
    go_ants(map2, map ,fl);
    del_map(&map);
    del_map(&map2);
    del_hash(hashtab,fl->hash_nbr);
    free(fl);
    // while(map)
    // {
    //     while(map->go)
    //     {
    //         printf("%s   ", map->go->sosed->key);
    //         map->go = map->go->next;
    //     }
    //     printf("\n\n\n");
    //     map = map->next;
    // }
}
