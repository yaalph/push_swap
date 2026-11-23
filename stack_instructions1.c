/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:13:17 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/21 16:40:28 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void reverse_rotate(t_stack **s)
{
    t_stack *last;
    t_stack *prev;

    if (!s || !*s || !(*s)->next)
        return;
    prev = NULL;
    last = *s;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *s;
    *s = last;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
}