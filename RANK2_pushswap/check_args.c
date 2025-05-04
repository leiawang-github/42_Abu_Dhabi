/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:36:21 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 10:10:32 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	no_duplicate_strs(char **strarr)
{
	int i = 0;
	int j;
	int k;

	while (strarr[i])
	{
		j = i + 1;
		while (strarr[j])
		{
			k = 0;
			while (strarr[i][k] && strarr[j][k] && strarr[i][k] == strarr[j][k])
				k++;
			if (strarr[i][k] == '\0' && strarr[j][k] == '\0')
				return (0); 
			j++;
		}
		i++;
	}
	return (1);
}

static int	within_int_limit(char **strarr)
{
	int i = 0;
	int j;
	long long n;
	int sign;

	while (strarr[i])
	{
		j = 0;
		sign = 1;
		n = 0;
		if (strarr[i][j] == '-' || strarr[i][j] == '+')
			if (strarr[i][j++] == '-')
				sign = -1;
		if (!strarr[i][j])
			return (0);
		while (strarr[i][j] >= '0' && strarr[i][j] <= '9')
			n = n * 10 + (strarr[i][j++] - '0');
		if (strarr[i][j] != '\0')
			return (0);
		n *= sign;
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static int	valid_ints_only(char **strarr)
{
	int i = 0;
	int j;

	if (!strarr)
		return (0);

	while (strarr[i])
	{
		j = 0;
		if (strarr[i][j] == '+' || strarr[i][j] == '-')
			j++;
		if (!strarr[i][j])
			return (0);
		while (strarr[i][j])
		{
			if (!ft_isdigit(strarr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int is_valid_split(char **strarr)
{
	if (!strarr)
		return (0);
	if (!valid_ints_only(strarr))
		return (0);
	if (!within_int_limit(strarr))
		return (0);
	if (!no_duplicate_strs(strarr))
		return (0);
	return (1);
}
