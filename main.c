/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:56:00 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/10 16:56:01 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

int main(int ac, char **av){
    t_stack *a = NULL;
    t_stack *b = NULL;
    parser(av, &a, &b);
    // ft_print_list(a);
    // ft_print_list(b);
    // radix_sort(&a, &b);
    
    // ft_print_list(a);
    // ft_print_list(b);
}