/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:08:10 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 18:42:18 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_to_stack_a(t_stack **stack_a, int value)
{
    t_stack *new_node;
    t_stack *temp;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return ;
    new_node->data = value;
    new_node->next = NULL;

    if (*stack_a == NULL) //如果一开始为空
        *stack_a = new_node;
    else
    {
        temp = *stack_a;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

void	print_stack(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int is_sorted(t_stack *stack)
{
	t_stack *temp;

	if (!stack)
		return (1);
	temp = stack;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0); 
		temp = temp->next;
	}
	return (1); 
}

int *stack_size(t_stack *stack)
{
	int count;

	count = 0;
	while (stack)
		count++;
	return (count);
}


void	free_stack(t_stack *stack)
{
	t_stack *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
