/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:36:21 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/21 18:26:29 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_not_dup(int ac, char **av) //判断输入的参数里是否有重复，有的话提示错误（返回0）
{
	int i;
	int j;

	i = 1;
	while (i < ac )
	{
		j = i + 1;
		while(j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int is_integer(int ac, char **av) //如果是小数不行，是字符串也不行
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        if ((av[i][j] == '-' || av[i][j] == '+') && av[i][j + 1] != '\0')
            j++;
        while (av[i][j])
        {
            if (!ft_is_digit(av[i][j]))
			{
				printf("Error\n");
				return (1);
			} 
            j++;
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
	int result = is_integer(ac,av);
	printf("%d\n",result);
}

int is_within_limits(int ac, char **av) 
{
	(void)ac;
	int i;

	i = 1;
	while(av[i])
	{
		if (av[i]>= INT_MIN && av[i] <= INT_MAX)
			return (0);
		i++;
	}
	printf("Error\n");
	return (1);
}
