/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:34:48 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/05 22:13:26 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (1);
	temp = stack;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (0);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*intarr;
	int		size;
	int		bit_len;

	stack_a = NULL;
	stack_b = NULL;
	bit_len = 0;
	if (argc < 2)
		return (0);
	intarr = argvs_to_intarr(argc, argv, &size);
	if (!intarr)
		return (1);
	if (!push_indexed_stack(&stack_a, intarr, size))
	{
		free(intarr);
		write(2, "Error\n", 6);
		return (1);
	}
	free(intarr);
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	if (stack_size(stack_a) <= 5)
		sort_small_stack(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b, size, bit_len);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
