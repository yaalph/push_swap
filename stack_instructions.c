/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:12:46 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/21 16:46:46 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
    tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
    tmp->next = (*b)->next;
	(*b)->next = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	if ((!a || !*a || !(*a)->next)
    	&& (!b || !*b || !(*b)->next))
		return;
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;


	if (!a || !b || !*b)
		return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;


	if (!b || !a || !*a)
		return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
}

void	ra(t_stack **a)
{
	t_stack	*first;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	ft_lstlast(*a)->next = first;
	first->next = NULL;
}

void	rb(t_stack **b)
{
	t_stack	*first;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	ft_lstlast(*b)->next = first;
	first->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
