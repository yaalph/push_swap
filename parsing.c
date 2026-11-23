/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-bagh <kal-bagh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 18:39:39 by kal-bagh          #+#    #+#             */
/*   Updated: 2026/11/23 09:30:31 by kal-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

void del_stack(t_stack **s)
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

void error_handler(t_stack **a, t_stack **b, int from_split, char **words){

    int i = 0;
    if(from_split){
        while(words[i])
            free(words[i++]);
        free(words);
    }
    
    if(a)
        del_stack(a);
    if(b)
        del_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


int is_duplicate(t_stack *a, int n){
    while(a){
        if(a->value == n)
            return 1;
        a = a->next;
    }
    return 0;
}

void validate_split_words(char **words, t_stack **a, t_stack **b){
    int sign = 1;
    int i = 0;
    int n = 0;
    int j = 0;
    t_stack *new;
    while(words[j]){
        sign = 1;
        i = 0;
        n = 0;
        if(words[j][i] == '-' || words[j][i] == '+'){
            if(words[j][i] == '-')
                sign = -1;
            i++;
        }
        if(!ft_isdigit(words[j][i]))
            error_handler(a, b, 1, words);
        while(1){
            while(words[j][i] == '0')
                i++;
            if(!words[j][i])
                break;
            while(ft_isdigit(words[j][i])){
                if(n < INT_MIN / 10 || (n == INT_MIN / 10 && words[j][i] - '0' > 8))
                    error_handler(a, b, 1, words);
                n = n * 10 - (words[j][i++] - '0');
            }
            if(words[j][i]) // if the end of while is_digit is not '\0'
                error_handler(a, b, 1, words);
            if(sign == 1 && n == INT_MIN)
                error_handler(a, b, 1, words);
            if(sign == 1)
                n *= -1;
            break;
        }
        if(is_duplicate(*a, n))
            error_handler(a, b, 1, words);
        new = ft_lstnew(n);
        if(!new)
            error_handler(a, b, 1, words);
        ft_lst_addback(a, new);
        j++;
    }
}

void free_words(char **words){
    int i = 0;
    while(words[i])
        free(words[i++]);
    free(words);
}



void parser(char **av, t_stack **a, t_stack **b){
    char **sub_args;
    while(*(++av)){
        if(ft_strncmp(*av, "--", 2) == 0)
            av += parse_flags(av, a, b);
        sub_args = ft_split(*av, " \t");
        if(!sub_args || !*sub_args)
            error_handler(a, b, 0, NULL);
        validate_split_words(sub_args, a, b);
        free(sub_args);
    }
}






























// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
// 		i++;
// 	if (i == n)
// 		return (0);
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }


// void ft_putstr(char *s){
//     while(*s){
//         write(1, s, ft_strlen(s));
//         s++;
//     }
// }

// void print_float(float n){
    
// }

// void first_upper(char *s){
//     char c = *s - ('a' - 'A');
//     write(1, &c, 1);
//     ft_putstr(s + 1);
// }

// void print_complexity(char *s){
//     if(ft_strncmp(s, "adaptive", ft_strlen("adaptive") == 0)){
//         first_upper(s);
//         ft_putstr(" / O(n√n)\n");
//     }
//     else if(ft_strncmp(s, "simple", ft_strlen("simple") == 0)){
//         write(1, "S", 1);
//         ft_putstr(s + 1);
//         ft_putstr(" / O(n²)\n");
//     }
//     else if(ft_strncmp(s, "medium", ft_strlen("medium") == 0)){
//         write(1, "S", 1);
//         ft_putstr(strategy + 1);
//         ft_putstr(" / O(n²)\n");
//     }
//     else if(ft_strncmp(s, "complex", ft_strlen("complex") == 0)){
//         ft_putstr(" / O(n²)\n");
//     }    
// }

// void bench_stats(float disorder, char *strategy, t_opcount opcount, char *adp){
//     ft_putstr("[bench] disorder: ");
//     print_float(disorder);
//     ft_putstr("%\n");
//     ft_putstr("[bench] strategy: ");
//     ft_putstr(strategy);
//     if(ft_strncmp(strategy, "adaptive", ft_strlen("adaptive") == 0)){
//         first_upper(adp);
//         ft_putstr(" / O(n√n)\n");
//     }
//     else if(ft_strncmp(strategy, "simple", ft_strlen("simple") == 0)){
//         write(1, "S", 1);
//         ft_putstr(strategy + 1);
//         ft_putstr(" / O(n²)\n");
//     }
//     else if(ft_strncmp(strategy, "medium", ft_strlen("medium") == 0)){
//         write(1, "S", 1);
//         ft_putstr(strategy + 1);
//         ft_putstr(" / O(n²)\n");
//     }
//     else if(ft_strncmp(strategy, "complex", ft_strlen("complex") == 0)){
//         write(1, "S", 1);
//         ft_putstr(strategy + 1);
//         ft_putstr(" / O(n²)\n");
//     }
// }


// int parse_flags(char **av, t_stack **a, t_stack **b){
//     int flags = 0;
//     while(av[flags] && ft_strncmp(av[flags], "--", 2) == 0)
//         flags++;

//     if(flags > 2 || (flags == 2 &&
//     (ft_strncmp(av[0], "--bench", ft_strlen("--bench") + 1)
//     && ft_strncmp(av[1], "--bench", ft_strlen("--bench") + 1))))
//             error_handler(a, b, 0, NULL);
//     int i_comp = 0;
//     if(flags == 2 && ft_strncmp(av[0], "--bench", ft_strlen("--bench") + 1) == 0)
//         i_comp = 1;

//     if(ft_strncmp(av[0], "--simple", ft_strlen("--simple") + 1) == 0)

// }