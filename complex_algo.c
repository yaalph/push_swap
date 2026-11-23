/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 04:22:44 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/23 05:30:16 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



int is_sorted(t_stack *s){

    if(!s)
        return 1;

    while(s->next){
        if((s->next)->rank < s->rank)
            return 0;
        s = s->next;
    }
    return 1;
}


int ft_bit_count(unsigned int n){
    int count = 0;
    while(n){
        n >>= 1;
        count++;
    }
    return count;
}

int ft_max_bit_count(t_stack *s){
    int max = 0;
    int bit_count;
    while(s){
        bit_count = ft_bit_count(s->rank);
        if(bit_count > max)
            max = bit_count;
        s = s->next;
    }
    return max;
}



void	ft_ops_addback(t_operation **lst, t_operation *new)
{
	t_operation	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
void del_ops(t_operation **ops)
{
	t_operation	*tmp;

	if (!ops)
		return ;
	while (*ops)
	{
		tmp = (*ops)->next;
        free(*ops);
		*ops = tmp;
	}
}


static void del_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
        free(*s);
		*s = tmp;
	}
}

t_operation	*ft_opnew(char* value)
{
	t_operation	*new;

	new = malloc(sizeof(t_operation));
	if (!new)
		return (NULL);
	new->op = value;
	new->next = NULL;
	return (new);
}

void ops_adding_helper(t_everything *everything, char *opr){
    t_operation *nw = ft_opnew(opr);
    if(!nw){
        del_ops(&everything->ops);
        del_stack(everything->a);
        del_stack(everything->b);
        exit(1);
    }
    ft_ops_addback(&everything->ops, nw);
}

void sort_a(int n, unsigned int mask, t_everything *everything);

void sort_b(int n, unsigned int mask, t_everything *everything){
    int zeroes = 0;
    int ones = 0;
    int all = 0;

    if(n <= 0)
        return;

    if(n == 1){
        pa(everything->a, everything->b);
        ops_adding_helper(everything, "pa");
        return;
    }
    
    if(n == 2){
        if((*everything->b)->rank < ((*everything->b)->next)->rank){
            sb(everything->b);
            ops_adding_helper(everything, "sb");
        }
        pa(everything->a, everything->b);
        ops_adding_helper(everything, "pa");
        pa(everything->a, everything->b);
        ops_adding_helper(everything, "pa");
        return;
    }

    if(n == ft_lstcount(*everything->b))
        all = 1;
    while(n--){
        if((*everything->b)->rank & mask){
            pa(everything->a, everything->b);
            ops_adding_helper(everything, "pa");
            ones++;
        }
        else{
            rb(everything->b);
            ops_adding_helper(everything, "rb");
            zeroes++;
        }
    }
    int i = 0;
    while(!all && i++ < zeroes){
        rrb(everything->b);
        ops_adding_helper(everything, "rrb");
    }
    sort_a(ones, mask >> 1, everything);
    sort_b(zeroes, mask >> 1, everything);
}


void sort_a(int n, unsigned int mask, t_everything *everything){
    int zeroes = 0;
    int ones = 0;
    int all = 0;


    if(n <= 1)
        return;
    
    if(n == 2){
        if((*everything->a)->rank > ((*everything->a)->next)->rank){
            sa(everything->a);
            ops_adding_helper(everything, "sa");
        }
        return;
    }

    if(n == ft_lstcount(*everything->a))
        all = 1;
    while(n--){
        if(!((*everything->a)->rank & mask)){
            pb(everything->a, everything->b);
            ops_adding_helper(everything, "pb");
            zeroes++;
        }
        else{
            ra(everything->a);
            ops_adding_helper(everything, "ra");
            ones++;
        }
    }
    int i = 0;
    while(!all && i++ < ones){
        rra(everything->a);
        ops_adding_helper(everything, "rra");
    }
    sort_a(ones, mask >> 1, everything);
    sort_b(zeroes, mask >> 1, everything);
}

void ft_putstr(char *s){
    while(*s)
        write(1, s++, 1);
    write(1, "\n", 1);
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

char *merge(char *x, char *y)
{
    if ((!ft_strcmp(x, "sa") && !ft_strcmp(y, "sb"))
        || (!ft_strcmp(x, "sb") && !ft_strcmp(y, "sa")))
        return ("ss");
    if ((!ft_strcmp(x, "ra") && !ft_strcmp(y, "rb"))
        || (!ft_strcmp(x, "rb") && !ft_strcmp(y, "ra")))
        return ("rr");
    if ((!ft_strcmp(x, "rra") && !ft_strcmp(y, "rrb"))
        || (!ft_strcmp(x, "rrb") && !ft_strcmp(y, "rra")))
        return ("rrr");
    return (NULL);
}

void optimise_ops(t_operation *ops){
    
    char *m;
    if(!ops)
        return ;
    if(!ops->next){
        ft_putstr(ops->op);
        return;
    }

    while(ops && ops->next){
        m = merge(ops->op, ops->next->op);
        if(m){
            ft_putstr(m);
            ops = ops->next;
        }
        else{
            ft_putstr(ops->op);
        }
        if(ops)
            ops = ops->next;
    }
    if(ops)
        ft_putstr(ops->op);
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

void radix_sort(t_stack **a, t_stack **b){
    
    assign_ranks(*a);
    if(is_sorted(*a))
        return;
    t_everything everything;
    everything.a = a;
    everything.b = b;
    everything.ops = NULL;
    int size = ft_lstcount(*a);
    sort_a(size, 1u << (ft_max_bit_count(*a) - 1), &everything);
    optimise_ops(everything.ops);
    del_ops(&everything.ops);
    del_stack(a);
    del_stack(b);
}
