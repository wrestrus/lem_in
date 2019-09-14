#include "lemin.h"

int check_ocher(t_way *dest, t_way *src)
{
    if(dest->sosed == NULL)
        return (1);
    while(src)
    {
        if(!strcmp(dest->sosed->key,src->sosed->key))
             return(0);
        src = src->next;
    }
    return(1);
}

int proverka_end(t_way *ochered, char *str)
{
    while(ochered)
    {
        if(!strcmp(ochered->sosed->key,str))
             return(0);
        ochered = ochered->next;
    }
    return(1);
}


void add_to_ochered(t_way **ochered, t_connection *temp, int line,  t_v *node)
{
    t_way *ochered1;
    t_way *ochered2;

    ochered2 = (t_way*)malloc(sizeof(t_way));
    ochered1 = *ochered;
    while(ochered1->next != NULL)
        ochered1 = ochered1->next;
    ochered2->sosed = temp->bonds;
    ochered2->next = NULL;
    ochered2->prev = node;
    ochered2->nomer_ant = 0;
    ochered2->revnext = ochered1;
    ochered2->poryadok = line;
    ochered1->next = ochered2;
    temp->bonds->is_node_one = 1;

}

void add_to_ochered2(t_way **ochered, t_connection *temp, int line,  t_v *node)
{
    t_way *ochered1;
    t_way *ochered2;

    ochered2 = (t_way*)malloc(sizeof(t_way));
    ochered1 = *ochered;
    while(ochered1->next != NULL)
        ochered1 = ochered1->next;
    ochered2->sosed = temp->bonds;
    if(check_ocher(ochered2, *ochered))
    {
        ochered2->next = NULL;
        ochered2->prev = node;
        ochered2->nomer_ant = 0;
        ochered2->revnext = ochered1;
        ochered2->poryadok = line;
        ochered1->next = ochered2;
    }
    else
        free(ochered2);
}


t_way *poisk_node_v_ochered(t_way **ochered, t_v *node)
{
    t_way *ptr;

    ptr = *ochered;
    while(ptr->sosed != node && ptr)
        ptr=ptr->next;
    return(ptr);
}


int one_from_zero(t_way *ptr,  t_v *node, t_way **ochered, int line )
{
    t_connection *temp;

    temp = node->knot;
    while(temp != NULL && temp->bonds->vizit != 1)
    {
        if(ft_strcmp(temp->bonds->key,(*ochered)->sosed->key) == 0)
        {
            if(temp->vizit == 0)
            break ;
        }
        temp = temp->next;
    }
    if(temp)
    {
        if(temp->bonds->vizit == 1)
            add_to_ochered(ochered, temp, line, node);
        return(1);
    }
    return(0);
}

void do_ochered(t_v **hashtab, char *start, t_way **ochered, int line, t_flag *fl)
{
    t_connection *temp;
    t_v *node;
    t_way *ptr;

    node = hashtab_lookup(hashtab, start, fl->hash_nbr);
    if(node->knot)
    {
        if(node->vizit == 1 && node->is_node_one == 0)
        {
            ptr = poisk_node_v_ochered (ochered, node);                  //из непосещенной
            if(ptr->prev->vizit == 0 )
            {
                if(one_from_zero(ptr, node, ochered, line) == 1)
                    return ;
            }
            else if(ptr->prev->vizit == 1)   // is poseshennoi
            {
                temp = node->knot;
                while(temp)
                {
                    if(temp->vizit == 0 &&  temp->bonds->vizit != 2)
                        add_to_ochered2(ochered, temp, line, node);
                    temp = temp->next;
                }
            }
        }
        if(node->vizit == 2)
            return;
        temp = node->knot;
        while(temp)
        {
            if(fl->poisk == 0)
            {
                if(temp->vizit == 0 &&  temp->bonds->vizit != 2)
                    add_to_ochered2(ochered, temp, line, node);
            }
            else
            {
                if(temp->vizit == 0 &&  temp->bonds->vizit == 0)
                    add_to_ochered2(ochered, temp, line, node);
            }
            temp = temp->next;
        }
    }
}

void create_ochered(t_way **ochered)
{
    *ochered = (t_way*)malloc(sizeof(t_way));
    (*ochered)->status = 0;
    (*ochered)->poryadok = 0;
    (*ochered)->revnext = NULL;
    (*ochered)->prev = NULL;
    (*ochered)->number = 0;
    (*ochered)->nomer_ant = 0;
}


void proverka_smezhreber(t_way *ochered,t_flag *fl)
{
    t_way *temp;
    int i;
    i = 0;

    temp = ochered;
    while(temp)
    {
        if(temp->sosed->smezh_rebro == 1)
            i++;
        if(i == 2)
        {
            fl->k = 0;
            temp->status = 1;
            temp->sosed->smezh_rebro = 2;
            temp = ochered;
            while(temp)
            {
                if(temp->sosed->smezh_rebro == 1)
                {
                    temp->sosed->smezh_rebro = 2;
                    break;
                }
                temp = temp->next;
            }
            break;
        }
        temp = temp->next;
    }
}




t_way  *ft_way(t_v **hashtab, char *start, char *end,t_flag *fl)
{
    t_v *node;
    t_way *ochered;
    t_way *temp;
    t_way *way;

    node = hashtab_lookup(hashtab, start, fl->hash_nbr);
    create_ochered(&ochered);
    ochered->sosed = node;
    temp = ochered;
    while(temp)
    {
        if(temp->status == 0)
        {
            do_ochered(hashtab, temp->sosed->key, &ochered, temp->poryadok + 1, fl);
            temp->status = 1;
        }
        if(fl->k == 1)
        {
            proverka_smezhreber(ochered,fl);
        }
        if(!proverka_end(ochered, end))
        {
            fl->c = 1;
            break;
        }
        temp = temp->next;
        fl->c = 0;
    }
    return(ochered);
}
