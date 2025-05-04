/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:13:49 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 22:14:24 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (0);
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
	return (1);
}

int	rra(t_stack **stack_a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return (0);
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	*stack_a = last;
	write(1, "rra\n", 4);
	return (1);
}
