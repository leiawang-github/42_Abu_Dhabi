/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:34:48 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/21 14:36:22 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	int i;
	
	i = 1;
	if (ac < 2)
		return(0);
	if (!is_not_dup(ac,av) || !is_integer(ac, av) || !is_within_limits(ac, av))
		return(1);
	while(i< ac)
	{
		push(&stack_a, ft_atoi(av[i]));
		i++;
	}
	if(ac == 2)
		return (0);
	else if ( )
	{
    	if (stack_a->data > stack_a->next->data)
        sa(&stack_a);  
	}
	else
		radix_sort(&stack_a, &stack_b);
	return (0);
}








