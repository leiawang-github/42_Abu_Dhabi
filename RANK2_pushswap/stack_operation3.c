#include "push_swap.h"

t_stack *create_node(int data) //创造了一个新节点，这个node孤伶伶地存在于stack上，不知道自己会被放入哪个链表
{
    t_stack *new_node = malloc(sizeof(t_stack));

    if (!new_node)
        return (NULL);
    new_node -> data = data;
    new_node -> next = NULL;
    return (new_node);
}

void add_back(t_stack **stack_a, t_stack *new_node)
{
    t_stack *temp;

    if (!stack_a || !new_node)
        return ;

    if (*stack_a == NULL)
    {
        *stack_a = new_node;
        return ;
    }

    temp = *stack_a;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}