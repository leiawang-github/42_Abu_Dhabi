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

int is_not_dup(char *str) //判断输入的参数里是否有重复，有的话提示错误（返回0）
{
	int i;
	int j;

	i = 0;
	while (i < ft_strlen(str) )
	{
		j = i + 1;
		while ( str[j])
		{
			if (str[i] == str[j])
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

int integers_only(char *str) //other than str[0] is '+' or '-' or nums, the str should be numstr
{
	int i;

	i = 1;
	if (str[0] != '+' && str[0] != '-' && (!('0' <= str[0] && str[0] <= '9')))
	{
		printf("Error\n");
		return (1);
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			printf("Error\n");
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
		printf("Error\n");
		return (1);
	}
	return (0);
}

