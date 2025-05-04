#include "push_swap.h"

int pa(t_stack **stack_a, t_stack **stack_b) // from b push to a
{
	t_stack *temp;
    
    if(*stack_b == NULL)
        return (0);
    temp = *stack_b;
    *stack_b = (*stack_b) -> next;
    temp -> next = *stack_a;
    *stack_a = temp;
    write(1, "pa\n", 3);
    return (1); 
}

int pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
    
    if(*stack_a == NULL)
        return (0);
    temp = *stack_a;
    *stack_a = (*stack_a) -> next;
    temp -> next = *stack_b;
    *stack_b = temp;
    write(1, "pb\n", 3); 
    return (1);
}

int ra(t_stack **stack_a) 
{
    t_stack *temp;
    t_stack *tail;
    
    if (*stack_a == NULL || (*stack_a)->next == NULL) 
        return (0);
    temp = *stack_a;
    *stack_a = (*stack_a) -> next; 
    tail = *stack_a;
    while(tail -> next != NULL)
        tail = tail -> next;
    tail->next = temp;  
    temp -> next =NULL;
    write(1, "ra\n", 3);
    return (1); 
}

int rb(t_stack **stack_b)
{
    t_stack *temp;
    t_stack *tail;
    
    if (*stack_b == NULL || (*stack_b)->next == NULL) 
        return (0);
    temp = *stack_b; 
    *stack_b = (*stack_b) -> next; 

    tail = *stack_b;
    while(tail -> next != NULL)
        tail = tail -> next;
    tail->next = temp;  
    temp -> next =NULL;
    write(1, "rb\n", 3); 
    return (1);
}

int sa(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return (0);
    first = *stack_a;
    second = (*stack_a)->next;

    first->next = second->next;
    second->next = first;
    *stack_a = second;
    write(1, "sa\n", 3);  
    return (1);
}

int sb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *second;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return (0);
    first = *stack_b;
    second = (*stack_b)->next;

    first->next = second->next;
    second->next = first;
    *stack_b = second;  
    write(1, "sb\n", 3); 
    return (1);
}

int rra(t_stack **stack_a) //rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
{
    t_stack *prev;
    t_stack *last;

    if(!*stack_a || !(*stack_a)->next)
        return;
    prev = NULL;
    last = *stack_a;
    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    *stack_a = last;
    write(1, "rra\n", 4); 
    return (1);
}
