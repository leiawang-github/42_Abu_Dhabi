/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:16:50 by leia              #+#    #+#             */
/*   Updated: 2025/05/04 22:15:39 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_two(t_stack **stack_a)
{
	sa(stack_a);
	return (1);
}

static int	sort_three(t_stack **stack_a, int count_ops)
{
	int	x;
	int	y;
	int	z;

	count_ops = 0;
	x = (*stack_a)->data;
	y = (*stack_a)->next->data;
	z = (*stack_a)->next->next->data;
	if (x > y && y < z && x < z)
		count_ops += sa(stack_a);
	else if (x > y && y > z)
	{
		count_ops += sa(stack_a);
		count_ops += rra(stack_a);
	}
	else if (x > y && y < z && x > z)
		count_ops += ra(stack_a);
	else if (x < y && y > z && x < z)
	{
		count_ops += sa(stack_a);
		count_ops += ra(stack_a);
	}
	else if (x < y && y > z && x > z)
		count_ops += rra(stack_a);
	return (count_ops);
}

static int	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	count_ops;
	int	min_idx;

	count_ops = 0;
	min_idx = find_min_index(*stack_a);
	count_ops += move_min_to_top(stack_a, min_idx);
	count_ops += pb(stack_a, stack_b);
	count_ops += sort_three(stack_a, count_ops);
	count_ops += pa(stack_a, stack_b);
	return (count_ops);
}

int	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_idx;
	int	count_ops;

	count_ops = 0;
	min_idx = find_min_index(*stack_a);
	count_ops += move_min_to_top(stack_a, min_idx);
	count_ops += pb(stack_a, stack_b);
	min_idx = find_min_index(*stack_a);
	count_ops += move_min_to_top(stack_a, min_idx);
	count_ops += pb(stack_a, stack_b);
	count_ops += sort_three(stack_a, count_ops);
	count_ops += pa(stack_a, stack_b);
	count_ops += pa(stack_a, stack_b);
	return (count_ops);
}

int	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	count_ops;

	size = stack_size(*stack_a);
	if (size == 1)
		return (1);
	if (size == 2)
		return (sort_two(stack_a));
	if (size == 3)
		return (sort_three(stack_a, count_ops));
	if (size == 4)
		return (sort_four(stack_a, stack_b));
	if (size == 5)
		return (sort_five(stack_a, stack_b));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*intarr;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
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
	return (0);
}
