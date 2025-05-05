/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:11:18 by leia              #+#    #+#             */
/*   Updated: 2025/05/05 11:41:57 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_int(t_stack *stack)
{
	int max_int;

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

static int get_bit_len(int max_int)
{
    int len;

    len = 0;
    while ((max_int >> len) != 0)
        len++;
    return (len);
}

int	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		bit_len;
	int		i;
	int		j;
	int		size;
	int		max_int;
	int		op_count;

	op_count = 0;
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
				op_count += pb(stack_a, stack_b);
			else
				op_count += ra(stack_a);
			j++;
		}
		while (*stack_b)
			op_count += pa(stack_a, stack_b);
		i++;
	}
    printf("need %d ops", op_count);
	return (op_count);
}

