#include "lemin.h"

void move_ants(t_allway  *map)
{
    t_allway *temp_map;
    t_way *temp;
    int c;

    temp_map = map;
    while(temp_map)
    {
        temp = temp_map->go;
        while(temp->next != NULL)
            temp = temp->next;
        while(temp->revnext != NULL )
        {
                c = temp->revnext->nomer_ant;
                temp->nomer_ant = c;
                temp = temp->revnext;
            }
            temp->nomer_ant = 0;
            temp_map = temp_map->next;
    }
    
}

void    sortirivka_way(t_allway  *map)
{
    t_allway *temp_map;
    t_allway *temp;
    t_allway *temp1;
    t_allway *temp2;
    int i;

    i = 0;
    while(i == 0)
    {
        temp_map = map;
        i = 1;
        while(temp_map->next)
        {
            if(temp_map->size < temp_map->next->size)
            {
                temp = temp_map;
                temp1 = temp_map->next;
                if(temp_map->prev)
                    temp2 = temp_map->prev;
                temp->next = temp1->next;
                temp1->next = temp;
                temp2->next = temp1;
                i = 0;
            }
            temp_map = temp_map->next;
        }
    }
}

void    count_way(t_allway  *map)
{
    t_way *temp;
    t_allway *temp_map;
    int i;

    i = 0;
    temp_map = map;
    while(temp_map)
    {
        i = 0;
        temp = temp_map->go;
        while(temp->next)
        {
            temp = temp->next;
            i++;
        }
        temp_map->size = i;
        temp_map = temp_map->next;

    }
}

void    count_raznica(t_allway  *map)
{
    t_way *temp;
    t_allway *temp_map;
    int i;

    i = 0;
    temp_map = map;
    temp_map->raznica = 0;
    while(temp_map->next)
    {
        i = temp_map->size - temp_map->next->size;
        temp_map->next->raznica = i;
        temp_map = temp_map->next;
    }
    map->naposl = temp_map;
}

int how_much_way(t_allway  *map,int ants)
{
    int i;
    t_allway *temp_map;

    temp_map = map->naposl;
    i = 1;
    while(ants >= 0 && temp_map->prev)
    {
        ants = ants - temp_map->raznica*i -1;
        if(ants < 0)
            break;
        i++;
        temp_map = temp_map->prev;
    }
    return(i);
}

void    first_way(t_allway  *map, t_flag *fl,int i)
{
    t_allway *temp_map;
    t_way *temp;

    temp_map = map->naposl;
   
    while(i-- && temp_map && fl->ants)
    {
        temp = temp_map->go;
        if(temp->next->nomer_ant == 0)
        {
            temp->next->nomer_ant = fl->p;
        }
        // else
        // {
        //     while(temp->next->nomer_ant != 0 && temp->next != NULL)
        //         temp = temp->next;
        //     temp = temp->next;
        //     while(temp->revnext->revnext != NULL && temp->revnext != 0)
        //     {
        //         temp->nomer_ant = temp->revnext->nomer_ant;
        //         temp = temp->revnext;
        //     }
        //     temp->nomer_ant = fl->p;
        // }
        fl->p++;
        fl->ants--;
        temp_map = temp_map->prev;
    }
}

void second_step(t_allway  *map, t_flag *fl,int i)
{
    t_allway *temp_map;
    t_way *temp;
    temp_map = map;
    while(temp_map )
    {
        temp = temp_map->go;
        //printf("%s %d\n",temp->next->sosed->key,temp->next->nomer_ant);
        while(temp->next != NULL)
        {
            if(temp->next->nomer_ant == 0)
                break;
            temp = temp->next;
        }
        if(temp->next != NULL)
            temp = temp->next;
        if(temp->next == NULL && temp->nomer_ant != 0)
        {
            printf("L%d-%s ",temp->nomer_ant,temp->sosed->key);
            temp->nomer_ant = 0;
        }
        //printf("\n\nsecond step = %s\n",temp->sosed->key);
       
        while(temp->revnext != NULL)
        {
            if(temp->revnext->nomer_ant != 0)
                printf("L%d-%s ",temp->revnext->nomer_ant,temp->revnext->sosed->key);
            temp = temp->revnext;
        }
        temp_map = temp_map->next;
    }
    printf("\n");
}



int     proverka_room(t_allway *map, t_flag *fl)
{
    t_allway *temp_map;
    t_way *temp;

    temp_map = map;
    while(temp_map)
    {
        temp = temp_map->go;
        while(temp)
        {
            if(temp->nomer_ant != 0)
                return(-1);
            temp = temp->next;
        }
        temp_map =temp_map->next;
    }
    return(0);
}

void print_ostal(t_allway  *map)
{
    t_allway *temp_map;
    t_way *temp;

    temp_map = map;
    while(temp_map)
    {
        temp = temp_map->go;
        while(temp)
        {   
            if(temp->nomer_ant != 0)
                printf("L%d-%s ",temp->nomer_ant, temp->sosed->key);
            temp= temp->next;
        }
        temp_map = temp_map->next;
    }
    printf("\n");
}

void go_ants(t_allway  *map_oneway, t_allway  *map , t_flag *fl)
{
    count_way(map);
    sortirivka_way(map);
    count_raznica(map);
    int i;
    int c;
    fl->p = 1;
    int j;
    fl->i = 0;
    //j = how_much_way(map,fl->ants);
    while(fl->ants)
    {
        i = how_much_way(map,fl->ants);
        move_ants(map);
        first_way(map, fl , i);
        print_ostal(map);
        fl->i++;
        // second_step(map, fl , j);
    }
    // move_ants(map);
    //  print_ostal(map);
    //  move_ants(map);
    // print_ostal(map);
    // // move_ants(map);
    // // print_ostal(map);
    // // move_ants(map);
    // // print_ostal(map);
    c = proverka_room(map, fl);
    while(c-- != 0)
    {
        move_ants(map);
        print_ostal(map);
        fl->i++;
        c = proverka_room(map, fl);
    }
    printf("%d\n\n",fl->i);
    // t_way *temp;
    // //  move_ants(map);
    // //  print_ostal(map);
    // //  move_ants(map);
    // //  print_ostal(map);
    // //   move_ants(map);
    // while(map)
    // {
    //     temp = map->go;
    //     while(temp)
    //     {
    //         printf(" %s  %d", temp->sosed->key, temp->nomer_ant);
    //         temp= temp->next;
    //     }
    //     printf("\n");
    //     map = map->next;
    // }
    // second_step(map, fl , i);
    
   //second_step(map, fl , j);
    //  move_ants(map);
    // second_step(map, fl , j);
    // move_ants(map);
    // second_step(map, fl , i);
    // move_ants(map);
    // second_step(map, fl , i);
    // move_ants(map);
    // second_step(map, fl , i);
    // move_ants(map);
    // second_step(map, fl , i);
    //  move_ants(map);
    // second_step(map, fl , i);
    //  move_ants(map);
    // second_step(map, fl , i);
    //  c = proverka_room(map, fl);
    // while(c != 0)
    // {
    //     move_ants(map);
    //     second_step(map, fl , i);
    //     c = proverka_room(map, fl);
    // }
    // i = how_much_way(map,fl->ants);
    // printf("skolko way %d\n",i);
    // first_way(map, fl , i);
    // second_step(map, fl , i);
    // printf("%d\n",fl->ants);
    // i = how_much_way(map,fl->ants);
    // printf("skolko way %d\n",i);
    // first_way(map, fl , i);
    // second_step(map, fl , i);
    // t_way *temp;
    // int c;
    // c = 5;
    // while(map && c--)
    // {
    //     temp = map->go;
    //     while(temp)
    //     {
    //         printf("%s    %d    ",temp->sosed->key,temp->nomer_ant);
    //         temp = temp->next;
    //     }
    //     printf("\n\n");
    //     map = map->next;
    // }


}
