/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:16:50 by leia              #+#    #+#             */
/*   Updated: 2025/05/05 22:05:49 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	x;
	int	y;
	int	z;

	x = (*stack_a)->data;
	y = (*stack_a)->next->data;
	z = (*stack_a)->next->next->data;
	if (x > y && y < z && x < z)
		sa(stack_a);
	else if (x > y && y > z)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (x > y && y < z && x > z)
		ra(stack_a);
	else if (x < y && y > z && x < z)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (x < y && y > z && x > z)
		rra(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_idx;

	min_idx = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_idx);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_idx;

	min_idx = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_idx);
	pb(stack_a, stack_b);
	min_idx = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_idx);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 1)
		return ;
	if (size == 2)
		sort_two(stack_a);
	if (size == 3)
		sort_three(stack_a);
	if (size == 4)
		sort_four(stack_a, stack_b);
	if (size == 5)
		sort_five(stack_a, stack_b);
}
