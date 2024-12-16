/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:05:19 by leiwang           #+#    #+#             */
/*   Updated: 2024/12/16 15:51:02 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
	{
		write(1, &c, 1);
		return (1);
	}
}

// int main(void)
// {
// 	int ret = ft_putchar('s', 100); 

// 	printf("ft_putchar returned: %d\n", ret); 
// }
