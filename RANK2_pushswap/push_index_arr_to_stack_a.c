/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_index_arr_to_stack_a.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:08:10 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/05 19:20:04 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	push_indexed_stack(t_stack **stack_a, int *intarr, int size)
{
	int	*copied;
	int	*sorted_copied;
	int	*index_arr;

	copied = copied_intarr(intarr, size);
	if (!copied)
		return (0);
	sorted_copied = sort_copied_intarr(copied, size);
	index_arr = map_to_index_array(intarr, sorted_copied, size);
	free(copied);
	if (!index_arr)
		return (0);
	push_to_stack(stack_a, index_arr, size);
	free(index_arr);
	return (1);
}
