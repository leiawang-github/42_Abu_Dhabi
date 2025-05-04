/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:16:50 by leia              #+#    #+#             */
/*   Updated: 2025/05/04 18:09:02 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int size;
    
    size = stack_size(*stack_a);
    if (size == 1)
        return (1);
    if (size == 2)
        return (sort_two(stack_a));
    if (size == 3)
        return (sort_three(stack_a));
    if (size == 4)
        return (sort_four(stack_a,stack_b));
    if (size == 5)
        return (sort_five(stack_a,stack_b));
    return (0);
}
static int	sort_two(t_stack **stack_a)
{
    sa(stack_a);
    return (1); 
}

static int	sort_three(t_stack **stack_a)
{
    int x, y, z;
    int count_ops;
   
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
	int ops_count;
    int	min_idx;

    ops_count = 0;
    min_idx = find_min_index(*stack_a);
	ops_count += move_min_to_top(stack_a, min_idx);
	ops_count += pb(stack_a, stack_b);
	ops_count += sort_three(stack_a);
	ops_count += pa(stack_a, stack_b);
    return (ops_count);
}

static int	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_idx;
    int count_ops;

    count_ops = 0;
	min_idx = find_min_index(*stack_a);
	count_ops += move_min_to_top(stack_a, min_idx);
	count_ops += pb(stack_a, stack_b);
	min_idx = find_min_index(*stack_a);
	count_ops += move_min_to_top(stack_a, min_idx);
	count_ops += pb(stack_a, stack_b);
	count_ops += sort_three(stack_a);
	count_ops += pa(stack_a, stack_b);
	count_ops += pa(stack_a, stack_b);
    return (count_ops);
}

int	find_min_index(t_stack *stack_a)
{
	int		min;
	int		index;
	int		i = 0;
	t_stack	*curr;

	min = stack_a->data;
    index = 0;
    curr = stack_a;
    while (curr)
	{
		if (curr->data < min)
		{
			min = curr->data;
			index = i;
		}
		i++;
		curr = curr->next;
	}
	return (index);
}

int	move_min_to_top(t_stack **stack_a, int min_index)
{
	int		size;
	int		i;
    int     count_ops;

    count_ops = 0;
    size = stack_size(*stack_a);
	if (min_index <= size / 2)
	{	
		i = 0;
        while (i++ < min_index)
            count_ops += rra(stack_a);		
	}
	else
	{
		i = 0;
		while (i++ < size - min_index)
			count_ops += rra(stack_a);
	}
    return (count_ops);
}
