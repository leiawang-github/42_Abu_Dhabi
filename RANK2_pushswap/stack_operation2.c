/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:08:10 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/21 14:08:41 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *stack) //计算出任意stack里面有多少个nodes
{
    int count = 0;
    t_stack *temp = stack;
    while (temp) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void push(t_stack **stack, int data)
{
    t_stack *newnode = malloc(sizeof(t_stack));
    if (!newnode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = *stack;
    *stack = newnode;
}

void pa(t_stack **stack_a, t_stack **stack_b) 
{
	t_stack *temp;
    
    if(*stack_b == NULL)
        return;
    temp = *stack_b;
    *stack_b = (*stack_b) -> next;
    temp -> next = *stack_a;
    *stack_a = temp;
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
    
    if(*stack_a == NULL)
        return;
    temp = *stack_a;
    *stack_a = (*stack_a) -> next;
    temp -> next = *stack_b;
    *stack_b = temp;;
}

void ra(t_stack **stack_a) 
{
    t_stack *temp;
    t_stack *tail;
    
    if (*stack_a == NULL || (*stack_a)->next == NULL) 
        return;
    temp = *stack_a;
    *stack_a = (*stack_a) -> next; 
    tail = *stack_a;
    while(tail -> next != NULL)
        tail = tail -> next;
    tail->next = temp;  
    temp -> next =NULL;
}

void rb(t_stack **stack_b)
{
    t_stack *temp;
    t_stack *tail;
    
    if (*stack_b == NULL || (*stack_b)->next == NULL) 
        return;
    temp = *stack_b; 
    *stack_b = (*stack_b) -> next; 

    tail = *stack_b;
    while(tail -> next != NULL)
        tail = tail -> next;
    tail->next = temp;  
    temp -> next =NULL;
}

void sa(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    first = *stack_a;
    second = (*stack_a)->next;

    first->next = second->next;
    second->next = first;
    *stack_a = second;  
}

void sb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *second;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first = *stack_b;
    second = (*stack_b)->next;

    first->next = second->next;
    second->next = first;
    *stack_b = second;  
}