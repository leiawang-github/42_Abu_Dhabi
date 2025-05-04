/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:00:57 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 17:47:52 by leia             ###   ########.fr       */
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

int	ft_isdigit(char c);
int is_valid_split(char **strarr);
int ft_split_size(char **split);
char *ft_strjoin(int argc, char **argv);
int ft_atoi(char *str);
char **ft_split(char *str, char c);
int *argvs_to_intarr(int argc, char **argv, int *size);
int stack_size(t_stack *stack);
int ft_split_size(char **split);
void free_strarr(char **strarr);
void free_all(char **strarr, char *str);
int is_sorted(t_stack *stack);
void radix_sort(t_stack **stack_a, t_stack **stack_b);
void add_to_stack_a(t_stack **stack_a, int value);
int sort_small(t_stack *stack_a, t_stack *stack_b);
int pa(t_stack **stack_a, t_stack **stack_b);
int pb(t_stack **stack_a, t_stack **stack_b);
int ra(t_stack **stack_a);
int rb(t_stack **stack_b);
int sa(t_stack **stack_a);
int sb(t_stack **stack_b);
int rra(t_stack **stack_a);
//int rrb(t_stack **stack_b);
//void print_stack(t_stack *stack_a);
void free_stack(t_stack *stack);
void	push_to_stack(t_stack **stack_a, int *arr, int size);

#endif
