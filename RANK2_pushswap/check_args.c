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

int no_dups(char **args)
{
	int i;
	int j;
	char **split;

	i = 0;
	split = ft_split(args, ' ');
	if(!split)
		return (NULL);
	while (split[i])
	{
		j = i + 1;
		while (split[j])
		{
			if (split[i] == split[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int integers_only(char *str) //other than str[0] is '+' or '-' or nums, the str should be numstr
{
	int i;

	i = 1;
	if (str[0] != '+' && str[0] != '-' && (!('0' <= str[0] && str[0] <= '9')))
	{
		printf("Error in Input\n");
		return (1);
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			printf("Error in Input\n");
			return (1);
		}
		i++;
	}
	return (0); 	
}

int	is_within_limits(char *str)
{
	long long result = 0;
	int sign = 1;

	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (0);
	result *= sign;
	if (result < INT_MIN || result > INT_MAX)
	{
		printf("Error in Input\n");
		return (1);
	}
	return (0);
}

int are_valid_args(char **args)
{
	int i;
	int j;
	char **split; // 这表示变量是split， 类型是char **；想象一个 字符串数组如： “hey" "how" "are" "you" 作为一个整体

	j = 0;
	split = ft_split(args, ' ');
	if (!split)
		return (1); // 啥时候是return 1， 啥时候是exit 1？
	while (split[j])
	{
		printf("%s\n",split[j]);
		if (!(integers_only(split[j]))) // z这个函数应该帮我们判断，是否只有integer，没有除了‘-’ ‘ +’ ‘0’ - ‘9’之外的字符
			return (free_split(split[j]), 1); 
		if (!(is_within_limits(split[j]))) // 判断这个字符串是否在INT范围内
			return (free_split(split[j]), 1); 
		if (!(no_dups(*split[j]))) // 这里得判断两点：每一个split[j] 都是独一无二的, 需要借助atoi判断
			return (free_split(split[j]), 1); 
	}
	free_split(split[i]);
	i++;
}