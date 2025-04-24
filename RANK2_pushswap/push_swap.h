/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:00:57 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/21 16:32:21 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct s_stack
{
	int data;
	struct s_stack *next;
}t_stack;

int ft_is_digit(char c);
int is_integer(int ac, char **av);
int is_not_dup(int ac, char **av);
int is_within_limits(int ac, char **av);
int ft_strcmp(char *s1, char *s2);
int	ft_atoi(char *str);
char **ft_split(char *str, char c);
void push(t_stack **stack, int data);
int stack_size(t_stack *stack);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void radix_sort(t_stack **stack_a, t_stack **stack_b);


#endif
