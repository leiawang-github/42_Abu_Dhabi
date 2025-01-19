/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:55:17 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/19 22:09:48 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int ft_strcmp(char *s1, char *s2)
// {
// 	int i;

// 	i = 0;
// 	while(s1[i]!= '\0' && s2[i] != '\0' )
// 	{
// 		if(s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }

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