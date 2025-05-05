/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:11:18 by leia              #+#    #+#             */
/*   Updated: 2025/05/05 19:38:26 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_int(t_stack *stack)
{
	int	max_int;

	max_int = 0;
	if (!stack)
		return (0);
	max_int = stack->data;
	while (stack)
	{
		if (stack->data > max_int)
			max_int = stack->data;
		stack = stack->next;
	}
	return (max_int);
}

static int	get_bit_len(int max_int)
{
	int	len;

	len = 0;
	while ((max_int >> len) != 0)
		len++;
	return (len);
}

int	radix_sort(t_stack **stack_a, t_stack **stack_b, int size, int bit_len)
{
	int	i;
	int	j;
	int	count_ops;
	int	max_int;

	count_ops = 0;
	max_int = get_max_int(*stack_a);
	bit_len = get_bit_len(max_int);
	size = stack_size(*stack_a);
	i = 0;
	while (i < bit_len)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->data >> i) & 1) == 0)
				count_ops += pb(stack_a, stack_b);
			else
				count_ops += ra(stack_a);
			j++;
		}
		while (*stack_b)
			count_ops += pa(stack_a, stack_b);
		i++;
	}
	return (count_ops);
}
