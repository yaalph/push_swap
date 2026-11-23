/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 01:10:53 by marvin            #+#    #+#             */
/*   Updated: 2026/11/11 14:33:30 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
float	compute_disorder(int a[], size_t arr_size)
{
	size_t	mistakes;
	size_t	i;
	size_t	j;
	size_t	total_pairs;

	mistakes = 0;
	i = 0;
	total_pairs = 0;
	while (i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			total_pairs++;
			if (a[i] > a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
