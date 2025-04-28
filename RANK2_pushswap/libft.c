/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:55:17 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/21 16:32:06 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i]!= '\0' && s2[i] != '\0' )
	{
		if(s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
        	str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char **ft_split(char *str, char c)
{
    (void) c;
	int i = 0;
    int j = 0;
    int k = 0;
    int wc = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0; 
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i; 
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			int m = 0;
			while (j < i)
				out[k][m++] = str[j++];
			out[k][m] = '\0'; 
			k++;
		}
	}
	out[k] = NULL;
	return out;
}

void free_split(char **split)
{
    int i = 0;

    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

#include <limits.h> // 为了 INT_MAX, INT_MIN

int ft_safe_atoi(const char *str, int *out)
{
    long long result = 0;
    int sign = 1;
    int i = 0;

    if (!str)
        return (0);

    // 跳过空格
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // 检查正负号
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    // 必须至少有一个数字
    if (!str[i])
        return (0);

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0); // 非数字字符
        
        result = result * 10 + (str[i] - '0');

        // 检查是否溢出
        if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
            return (0);

        i++;
    }

    *out = (int)(result * sign);
    return (1); // 成功
}