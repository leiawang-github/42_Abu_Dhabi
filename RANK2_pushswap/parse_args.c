#include "push_swap.h"

int parse_args(int argc, char **argv, t_stack **stack_a)
{
    int     i;
    char    **split;
    int     j;

    i = 1;
    while (i < argc)
    {
        split = ft_split(argv[i], ' ');  // 拆分每个 av[i]
        if (!split)
            return (error());

        j = 0;
        while (split[j])
        {
            // 检查是否为合法整数，例如 is_valid_integer(split[j])
            // 再 atoi 然后装进链表
            
            
            
            
            
            j++;
        }
        free_split(split); // 释放 ft_split 分配的数组
        i++;
    }
    return (0);
}