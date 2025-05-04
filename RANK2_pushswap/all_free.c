/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:23:13 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 21:27:13 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **strarr, char *str)
{
	free_strarr(strarr);
	free(str);
}

void	free_strarr(char **strarr)
{
	int	i;

	i = 0;
	if (!strarr)
		return ;
	while (strarr[i])
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
