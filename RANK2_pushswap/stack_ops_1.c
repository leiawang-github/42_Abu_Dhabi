/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:04:24 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 22:14:45 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b == NULL)
		return (0);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return (0);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
	return (1);
}

int	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*tail;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	tail = *stack_a;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*tail;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (0);
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	tail = *stack_b;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
	return (1);
}
