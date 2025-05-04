/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:34:48 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 18:20:11 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	int *intarr;
	int size;

	if (argc < 2)
		return (0);

	intarr = argvs_to_intarr(argc, argv, &size);
	if (!intarr)
		return (1);
	push_to_stack(&stack_a, intarr, size);
	free(intarr);
	if (is_sorted(stack_a))
		return (free_stack(stack_a), 0);
	if (stack_size(stack_a) <= 5)
		sort_small(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

void	push_to_stack(t_stack **stack_a, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		add_to_stack_a(stack_a, arr[i]);
		i++;
	}
}
