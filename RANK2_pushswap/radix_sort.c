/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:11:18 by leia              #+#    #+#             */
/*   Updated: 2025/05/04 18:10:15 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max(t_stack *stack)
{
    int max = INT_MIN;
    while (stack)
    {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    return max;
}

int get_digit(int num, int pos)
{
    return (num / pos) % 10;
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max = get_max(*stack_a);
    int pos = 1;

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
}
