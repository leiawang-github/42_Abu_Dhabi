#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int data;
	struct s_stack *next;
} t_stack;

t_stack *create_node(int data)
{
    t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

void print_list(t_stack *stack_a)
{
    t_stack *temp = stack_a;
    while (temp)
    {
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
    temp = stack_a;
    { while (temp)
        {
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
    }
}

int main(void)
{
    t_stack *stack_a = NULL;
    t_stack *n1 = create_node(42);
    t_stack *n2 = create_node(18);
    t_stack *n3 = create_node(34);

    stack_a = n1;
    n1->next = n2;
    n2->next = n3;

    print_list(stack_a);
    return (0);
}