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

    if (*stack_a == NULL)
        *stack_a = new_node;
    else
    {
        temp = *stack_a;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

int parse_args(int argc, char **argv, t_stack **stack_a)
{
    int     i, j;
    char    **split;

    i = 1;
    while (i < argc)
    {
        split = ft_split(argv[i], ' ');
        if (!split)
            return (1);
        j = 0;
        while (split[j]) 
        {
            if (is_not_dup(split[j]) == 0 && integers_only(split[j]) == 0 && is_within_limits(split[j]) == 0)
            {
                int value;
                if (!ft_safe_atoi(split[j], &value))
                    return (1);
                add_to_stack_a(stack_a, value);
            }
            j++;
        }
        free_split(split);
        i++;
    }
    return (0);
}

void print_stack_a(t_stack *stack_a)
{
    t_stack *temp = stack_a;

    while (temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(int ac, char **av)
{
    t_stack *stack_a = NULL;
    if (parse_args(ac,av,&stack_a) == 1)
    {
        printf("Parsing Error");
        return (1);
    }
    print_stack_a(stack_a);
}