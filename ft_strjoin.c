/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 11:46:22 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/22 09:05:52 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	i;
	size_t	to_alloc;

	i = 0;
	if (!s1 || !s2 || ft_strlen(s1) + 1 > SIZE_MAX - ft_strlen(s2))
		return (NULL);
	to_alloc = ft_strlen(s1) + ft_strlen(s2);
	buff = malloc(to_alloc + 1);
	if (!buff)
		return (NULL);
	while (*s1)
		buff[i++] = *s1++;
	while (*s2)
		buff[i++] = *s2++;
	buff[i] = '\0';
	return (buff);
}

// #include <stdio.h>
// int main(){

//     char *s1 = "";
//     char *s2 = "  ";
//     printf("%s\n", ft_strjoin(s1, s2));

// }