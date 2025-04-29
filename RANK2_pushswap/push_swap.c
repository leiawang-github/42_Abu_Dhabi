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

    if (ac > 1)
    {
        if (valid_args(av + 1) == 0) // 检查参数是否合法
        {
            if (add_args_to_stack(av + 1, &stack_a) != 0)
            {
                write(2, "Error\n", 6);
                return (1);
            }
            if (is_sorted(stack_a))
            {
                free_stack(stack_a);
                return (0); // 排好了直接退出
            }
            if (stack_size(stack_a) <= 5)
                sort_small(&stack_a, &stack_b);
            else
                sort_big(&stack_a, &stack_b);
            free_stack(stack_a);
            free_stack(stack_b); // 注意 stack_b也要 free（即使可能是空的）
        }
        else
        {
            write(2, "Error\n", 6);
            return (1);
        }
    }
    return (0);
}
