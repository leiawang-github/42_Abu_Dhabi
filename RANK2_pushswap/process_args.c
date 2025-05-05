/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:41:01 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/05 18:46:32 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**argvs_to_split(int argc, char **argv)
{
	char	*joined_args;
	char	**split;

	joined_args = ft_strjoin(argc, argv);
	if (!joined_args)
		return (NULL);
	split = ft_split(joined_args, ' ');
	if (!split)
	{
		free(joined_args);
		return (NULL);
	}
	if (!is_valid_split(split))
	{
		write(2, "Error\n", 6);
		free_all(split, joined_args);
		return (NULL);
	}
	free(joined_args);
	return (split);
}

static int	*split_to_intarr(char **split, int *out_size)
{
	int	*intarr;
	int	i;
	int	size;

	i = 0;
	size = ft_split_size(split);
	intarr = malloc(sizeof(int) * size);
	if (!intarr)
		return (NULL);
	while (i < size)
	{
		intarr[i] = ft_atoi(split[i]);
		i++;
	}
	*out_size = size;
	return (intarr);
}

int	*argvs_to_intarr(int argc, char **argv, int *size)
{
	char	**split;
	int		*intarr;

	split = argvs_to_split(argc, argv);
	if (!split)
		return (NULL);
	intarr = split_to_intarr(split, size);
	free_strarr(split);
	return (intarr);
}
