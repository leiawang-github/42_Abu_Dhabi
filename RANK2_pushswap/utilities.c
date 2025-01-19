/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:36:21 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/19 22:21:43 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int	count_para(int ac, char **av) // now we know hoe many paras we have as argruments
{
	(void)av;
	return (ac - 1);
}

// int is_double(int ac, char **av)
// {
// 	int para_size;
// 	int i;
// 	int j;

// 	i = 1;
// 	para_size = count_para(ac, av);
// 	while(i < para_size)
// 	{
// 		j = i + 1;
// 		while(j < para_size)
// 		{
// 			if (ft_strcmp(av[i], av[j]) == 0)
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int not_integer(int ac, char **av)
{
	int  para_size;
	int i;
	int j;

	i = 1;

	para_size = count_para(ac, av);
	while (i < para_size)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if(!ft_is_digit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int main(int ac, char** av)
{
	(void)ac;

	printf("%d",not_integer(ac, av));
}
	    

