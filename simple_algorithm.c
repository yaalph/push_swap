/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:57:18 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/10 18:57:18 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void selection_sort(t_stack **a, t_stack **b){

    if(!a || !*a || !b)
        return;
    t_stack *sa;
    t_stack *min;
    while(*a){
        sa = *a;
        min = *a;
        while(sa){
            if(sa->value < min->value)
                min = sa;
            sa = sa->next;
        }
        while(min != *a)
            r_a_or_b(a, 'a', 0);
        p_a_or_b(b, a, 'a');
    }

    while(*b)
        p_a_or_b(a, b, 'b');
}