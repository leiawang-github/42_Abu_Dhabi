/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:55:17 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 12:36:00 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void free_strarr(char **strarr)
{
    int i = 0;

    if (!strarr)
        return;
    while (strarr[i])
    {
        free(strarr[i]);
        i++;
    }
    free(strarr);
}

void	free_all(char **strarr, char *str)
{
	free_strarr(strarr);
	free(str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	turn_possitive;

	i = 0;
	result = 0;
	turn_possitive = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		turn_possitive = turn_possitive * (-1);
		i++;
	}
	else if (str[i] == '+')
	{
		turn_possitive = turn_possitive * 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * turn_possitive);
}

static int	get_total_length(int argc, char **argv)
{
	int i = 1;
	int len = 0;
	while (i < argc)
		len += ft_strlen(argv[i++]);
	return len + (argc - 2) + 1; 
}

char *ft_strjoin(int argc, char **argv)
{
	int i = 1, k = 0, j;
	int total_len = get_total_length(argc, argv);
	char *result = malloc(total_len);
	if (!result)
		return NULL;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			result[k++] = argv[i][j++];
		if (i != argc - 1)
			result[k++] = ' ';
		i++;
	}
	result[k] = '\0';
	return result;
}

static int	count_words(char *str, char c)
{
	int i = 0, count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return count;
}
static char	*alloc_word(char *s, int start, int end)
{
	char *word = malloc(end - start + 1);
	int i = 0;
	if (!word)
		return NULL;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return word;
}
char **ft_split(char *s, char c)
{
	int i = 0, j, k = 0;
	char **res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return NULL;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			res[k++] = alloc_word(s, j, i);
	}
	res[k] = NULL;
	return res;
}
int ft_split_size(char **split)
{
    int count;
    
    count = 0;
    if (!split)
        return 0;
    while (split[count])
        count++;
    return count;
}