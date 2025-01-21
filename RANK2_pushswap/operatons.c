/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatons.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:08:10 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/21 12:06:20 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void pb(t_stack **stack_a, t_stack **stack_b) // 想实现把stack a的最上面元素push到stack b中去
{
	t_stack *temp;
    
    if(*stack_a == NULL)
        return;
    temp = *stack_a;
    *stack_a = (*stack_a) -> next;
    temp -> next = *stack_b;
    *stack_b = temp;;
}

void pa(t_stack **stack_a, t_stack **stack_b) // 想实现把stack a的最上面元素push到stack b中去
{
	t_stack *temp;
    
    if(*stack_b == NULL)
        return;
    temp = *stack_b;
    *stack_b = (*stack_b) -> next;
    temp -> next = *stack_a;
    *stack_a = temp;
}

void ra(t_stack **stack_a) 
{
    t_stack *temp;
    t_stack *tail;
    
    if (*stack_a == NULL || (*stack_a)->next == NULL) // 为空链表或者只有一个节点
        return 0;
    temp = *stack_a; //保存了第一个节点结构体
    *stack_a = (*stack_a) -> next; //原本的头节点指向了下一个节点

    tail = *stack_a;
    while(tail -> next != NULL)
        tail = tail -> next;
    tail->next = temp;  
    temp -> next =NULL;
}

int rb(t_stack **stack_b)
{
    t_stack *temp;
    t_stack *tail;
    
    if (*stack_b == NULL || (*stack_b)->next == NULL) // 为空链表或者只有一个节点
        return 0;
    temp = *stack_b; //保存了第一个节点结构体
    *stack_b = (*stack_b) -> next; //原本的头节点指向了下一个节点

    tail = *stack_b;
    while(tail -> next != NULL)
        tail = tail -> next;
    tail->next = temp;  
    temp -> next =NULL;
}

//创建节点
// t_stack *newnode(int data)
// {
//     t_stack *newnode;
//     newnode = (t_stack*)malloc(sizeof(t_stack));

//     newnode -> data = data;
//     newnode -> next = NULL;
//     return (newnode);
// }
// void print_stack(t_stack *stack_a, t_stack *stack_b)
// {
//     printf("Stack_a: ");
//     while (stack_a)
//     {
//         printf("%d -> ", stack_a -> data);
//         stack_a = stack_a -> next;
//     }
//     printf("NULL\n");
  
//     printf("Stack_b: ");
//     while (stack_b)
//     {
//         printf("%d -> ", stack_b -> data);
//         stack_b = stack_b -> next;
//     }
//     printf("NULL\n");
// }

// int main()
// {
//     // 手动创建stack_a链表: 1 -> 2 -> 3 -> 4 -> 5
//     t_stack *stack_a = newnode(13);
//     stack_a->next = newnode(22);
//     stack_a->next->next = newnode(3);
//     stack_a->next->next->next = newnode(46);
//     stack_a->next->next->next->next = newnode(75);

//    t_stack *stack_b = newnode(121);
//    stack_b -> next = newnode(99);
//    stack_b -> next -> next = newnode(666);

//     print_stack(stack_a,stack_b);
    
//     // 调用pb函数，将stack_a顶部元素移到stack_b
//     pb(&stack_a, &stack_b);
//     pb(&stack_a, &stack_b);
//     pb(&stack_a, &stack_b);
//     pb(&stack_a, &stack_b);
//     pb(&stack_a, &stack_b);

//     pa(&stack_a, &stack_b);
//     pa(&stack_a, &stack_b);
//     pa(&stack_a, &stack_b);
    

//     printf("\nStack A after oprations: ");
//     print_stack(stack_a,stack_b);
    
//     return 0;
   
// }