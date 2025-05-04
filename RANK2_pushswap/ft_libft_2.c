/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:03:00 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 22:05:47 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*alloc_word(char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(end - start + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = 0;
	k = 0;
	res = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		j = i;
		while (str[i] && str[i] != c)
			i++;
		if (i > j)
			res[k++] = alloc_word(str, j, i);
	}
	res[k] = NULL;
	return (res);
}

int	ft_split_size(char **split)
{
	int	count;

	count = 0;
	if (!split)
		return (0);
	while (split[count])
		count++;
	return (count);
}
