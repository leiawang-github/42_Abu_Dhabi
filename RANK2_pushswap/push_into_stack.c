/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:08:10 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 23:23:09 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*intarr_copy_and_sort(int *intarr, int size)
{
	int	*sorted;
	int	i;
	int	j;
	int	tmp;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = intarr[i];
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[i] > sorted[j])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}

int	*map_to_index_array(int *intarr, int *sorted, int size)
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
			if (intarr[i] == sorted[j])
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

void	add_to_stack_a(t_stack **stack_a, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = NULL;
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
	{
		temp = *stack_a;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	push_to_stack(t_stack **stack_a, int *index_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		add_to_stack_a(stack_a, index_arr[i]);
		i++;
	}
}


int	parse_and_push_indexed_stack(t_stack **stack_a, int *raw, int size)
{
	int	*sorted;
	int	*index_arr;

	sorted = intarr_copy_and_sort(raw, size);
	if (!sorted)
		return (0);
	index_arr = map_to_index_array(raw, sorted, size);
	free(sorted);
	if (!index_arr)
		return (0);
	push_to_stack(stack_a, index_arr, size);
	free(index_arr);
	return (1);
}


