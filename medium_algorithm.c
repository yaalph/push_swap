/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:07:42 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/17 09:17:52 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

int square_root(int count){

    if(count == 1)
        return 1;

    int x = 2;
    while(x < count / x)
        x++;
    if(x != count / x)
        x--;
    return x;    
}

void assign_ranks(t_stack *s){
    t_stack *i = s;
    int r;
    t_stack *j;
    while(i){
        j = s;
        r = 0;
        while(j){
            if(j->value < i->value)
                r++;
            j = j->next;
        }
        i->rank = r;
        i = i->next;
    }
}

int in_chunk(int chunk, int elems, int rank, int n_chunks){
    if(chunk == n_chunks - 1)
        return rank >= elems * chunk;
    return rank < elems * (chunk + 1) && rank >= elems * chunk;
}

void chunking(t_stack **a, t_stack **b){
    int n_chunks = square_root(ft_lstcount(*a));
    int nodes = ft_lstcount(*a);
    int elems = nodes / n_chunks;
    int i = 0;
    int j = 0;
    int scanned = 0;
    while(*a){
        i = 0;
        scanned = 0;
        nodes = ft_lstcount(*a);
        while(*a && scanned++ < nodes && ((i < elems && j < n_chunks - 1) || j == n_chunks - 1)){
            if(in_chunk(j, elems, (*a)->rank, n_chunks)){
                (*a)->chunk = j;
                pb(a, b);
                i++;
            }
            else
                ra(a);
        }
        j++;
    }
}


t_stack *retrieve_max(t_stack *s, int chunk){
    t_stack *max = NULL;
    while(s){
        if(s->chunk == chunk && (max == NULL || s->value > max->value))
            max = s;
        s = s->next;
    }
    return max;
}


void chunk_based(t_stack **a, t_stack **b){
    assign_ranks(*a);
    chunking(a, b);
    t_stack *max;
    int x;

    while(*b){
        max = retrieve_max(*b, (*b)->chunk);
        x = 0;
        while(*b != max){
            rb(b);
            x++;
        }
        pa(a, b);
        while(x--)
            rrb(b);
    }
}