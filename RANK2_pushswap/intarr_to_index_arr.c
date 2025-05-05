/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intarr_to_index_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:06:42 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/05 19:21:18 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copied_intarr(int *intarr, int size)
{
	int	i;
	int	*copied_intarr;

	copied_intarr = malloc(sizeof(int) * size);
	if (!copied_intarr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copied_intarr[i] = intarr[i];
		i++;
	}
	return (copied_intarr);
}

int	*sort_copied_intarr(int *copied_intarr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size -1)
		{
			if (copied_intarr[i] > copied_intarr[j])
			{
				temp = copied_intarr[i];
				copied_intarr[i] = copied_intarr[j];
				copied_intarr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (copied_intarr);
}

int	*map_to_index_array(int *intarr, int *copied_intarr, int size)
{
	int	*index_arr;
	int	i;
	int	j;

	index_arr = malloc(sizeof(int) * size);
	if (!index_arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (intarr[i] == copied_intarr[j])
			{
				index_arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (index_arr);
}
