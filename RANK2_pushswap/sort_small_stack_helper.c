/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:41:58 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/05 06:28:35 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack_a)
{
	int		min;
	int		index;
	int		i;
	t_stack	*curr;

	i = 0;
	min = stack_a->data;
	index = 0;
	curr = stack_a;
	while (curr)
	{
		if (curr->data < min)
		{
			min = curr->data;
			index = i;
		}
		i++;
		curr = curr->next;
	}
	return (index);
}

int	move_min_to_top(t_stack **stack_a, int min_index)
{
	int	size;
	int	i;
	int	count_ops;

	count_ops = 0;
	size = stack_size(*stack_a);
	if (min_index <= size / 2)
	{
		i = 0;
		while (i++ < min_index)
			count_ops += ra(stack_a);
	}
	else
	{
		i = 0;
		while (i++ < size - min_index)
			count_ops += ra(stack_a);
	}
	return (count_ops);
}
