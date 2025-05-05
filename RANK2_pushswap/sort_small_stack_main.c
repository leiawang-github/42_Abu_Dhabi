/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_main.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:16:50 by leia              #+#    #+#             */
/*   Updated: 2025/05/05 11:34:43 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_two(t_stack **stack_a)
{
	sa(stack_a);
	return (printf("1\n"));
}

// static int	sort_three(t_stack **stack_a, int count_ops)
// {
// 	int	x;
// 	int	y;
// 	int	z;

// 	count_ops = 0;
// 	x = (*stack_a)->data;
// 	y = (*stack_a)->next->data;
// 	z = (*stack_a)->next->next->data;
// 	if (x > y && y < z && x < z)
// 		count_ops += sa(stack_a);
// 	else if (x > y && y > z)
// 	{
// 		count_ops += sa(stack_a);
// 		count_ops += rra(stack_a);
// 	}
// 	else if (x > y && y < z && x > z)
// 		count_ops += ra(stack_a);
// 	else if (x < y && y > z && x < z)
// 	{
// 		count_ops += sa(stack_a);
// 		count_ops += ra(stack_a);
// 	}
// 	else if (x < y && y > z && x > z)
// 		count_ops += rra(stack_a);
// 	return (printf("need %d ops\n",count_ops));
// }
static int	sort_three(t_stack **stack_a)
{
	int x;
	int y;
	int z;
	int count_ops;

	count_ops = 0;
	x = (*stack_a)->data;
	y = (*stack_a)->next->data;
	z = (*stack_a)->next->next->data;
	if (x > y && y < z && x < z)
		count_ops += sa(stack_a);
	else if (x > y && y > z)
		count_ops += sa(stack_a), count_ops += rra(stack_a);
	else if (x > y && y < z && x > z)
		count_ops += ra(stack_a);
	else if (x < y && y > z && x < z)
		count_ops += sa(stack_a), count_ops += ra(stack_a);
	else if (x < y && y > z && x > z)
		count_ops += rra(stack_a);
	//printf("need %d ops\n", count_ops);
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
	count_ops += sort_three(stack_a);
	count_ops += pa(stack_a, stack_b);
	return (printf("need %d ops\n",count_ops));
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
	count_ops += sort_three(stack_a);
	count_ops += pa(stack_a, stack_b);
	count_ops += pa(stack_a, stack_b);
	printf("need %d ops\n",count_ops);
	return (count_ops);
}



int	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	//int	count_ops;

	size = stack_size(*stack_a);
	if (size == 1)
		printf("1");
	if (size == 2)
		sort_two(stack_a);
	if (size == 3)
		sort_three(stack_a);
	if (size == 4)
		sort_four(stack_a, stack_b);
	if (size == 5)
		sort_five(stack_a, stack_b);
	return (0);
}


// static void	print_stack(t_stack *stack)
// {
// 	t_stack *temp;

// 	temp = stack;
// 	while (temp)
// 	{
// 		printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// }

