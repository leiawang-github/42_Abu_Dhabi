/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:11:18 by leia              #+#    #+#             */
/*   Updated: 2025/05/04 21:09:20 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	get_digit(int num, int pos)
{
	return ((num / pos) % 10);
}

int	radix_sort(t_stack **stack_a, t_stack **stack_b) // updated
{
	int count_ops;
	int max = get_max(*stack_a);
	int pos = 1;

	count_ops;
	while (max / pos > 0)
	{
		t_stack *current = *stack_a;
		while (current)
		{
			if (get_digit(current->data, pos) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			current = current->next;
		}
		while (*stack_b)
			pa(stack_a, stack_b);

		pos *= 10;
	}
	return (count_ops);
}
