/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:34:48 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/05 11:31:25 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*intarr;
	int		size;
	int		max_int;

	stack_a = NULL;
	stack_b = NULL;
	max_int = 0;
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
		sort_small_stack(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int		*intarr;
// 	int		size;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	if (argc < 2)
// 		return (0);
// 	intarr = argvs_to_intarr(argc, argv, &size);
// 	// printf("%d\n", intarr[0]);
// 	// printf("%d\n", intarr[1]);
// 	// printf("%d\n", intarr[2]);
// 	// printf("%d\n", intarr[3]);
	
// 	if (!intarr)
// 		return (1);
// 	push_to_stack(&stack_a, intarr, size);
// 	free(intarr);
	
// 	if (is_sorted(stack_a))
// 	{
// 		printf("OK\n");
// 		free_stack(stack_a);
// 		return (0);
// 	}
// 	if (stack_size(stack_a) <= 5)
// 	{
// 		printf("stack size: %d\n", stack_size(stack_a));
// 		sort_small_stack(&stack_a, &stack_b);
// 	}
// 	return (0);
// }