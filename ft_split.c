/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 07:20:22 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/22 07:37:47 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "pushswap.h"

int	ft_issep(char *charset, char c)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static size_t	count_words(char const *s, char *charset, size_t end)
{
	size_t	cnt;
	size_t	i;

	cnt = 1;
	i = 0;
	while (i <= end && s[i])
	{
		if (ft_issep(charset, s[i]))
		{
			cnt++;
			while (i <= end && s[i] && ft_issep(charset, s[i]))
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static void	*skip_leading_trailing_seps(char const **s, size_t *end,
		char *charset, size_t *word_count)
{
	while (**s && ft_issep(charset, **s))
		(*s)++;
	if (ft_strlen(*s) == 0)
	{
		*end = 0;
		*word_count = 0;
		return (malloc((*word_count + 1) * sizeof(char *)));
	}
	*end = ft_strlen(*s) - 1;
	while (*end && ft_issep(charset, (*s)[*end]))
		(*end)--;
	*word_count = count_words(*s, charset, *end);
	return (malloc((*word_count + 1) * sizeof(char *)));
}

static size_t	word_len(char const *s, size_t end, char *charset)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (i <= end && s[i] && !ft_issep(charset, s[i]))
	{
		cnt++;
		i++;
	}
	return (cnt);
}

static void	*sub_func(char const **s, size_t end, char *charset)
{
	size_t	j;
	char	*word;

	j = 0;
	word = malloc(word_len(*s, end, charset) + 1);
	if (!word)
		return (NULL);
	while (**s && !ft_issep(charset, **s))
		word[j++] = *((*s)++);
	word[j] = '\0';
	while (**s && ft_issep(charset, **s))
		(*s)++;
	return (word);
}

char	**ft_split(char const *s, char *charset)
{
	size_t	end;
	size_t	i;
	size_t	word_count;
	char	**buff;

	if (!s)
		return (NULL);
	i = 0;
	buff = skip_leading_trailing_seps(&s, &end, charset, &word_count);
	if (!buff)
		return (NULL);
	buff[word_count] = NULL;
	while (i < word_count)
	{
		buff[i] = sub_func(&s, end, charset);
		if (!buff[i])
		{
			while (i > 0)
				free(buff[--i]);
			free(buff);
			return (NULL);
		}
		i++;
	}
	return (buff);
}

// #include <stdio.h>
// int main(){

//     char const *s = NULL;
//     char c = ' ';
//     size_t i = 0;
//     size_t end = 0;
//     char **buff = ft_split(s, c);
//     while(buff[i]){
//         printf("%s\n", buff[i]);
//         free(buff[i++]);
//     }
//     free(buff);
//     // skip_leading_trailing_seps(&s, &end, 'l');
//     // printf("%zu\n", count_words(s, c, end));
// }