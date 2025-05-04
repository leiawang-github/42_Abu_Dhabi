/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:55:17 by leiwang           #+#    #+#             */
/*   Updated: 2025/05/04 22:02:53 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	turn_possitive;

	i = 0;
	result = 0;
	turn_possitive = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		turn_possitive = turn_possitive * (-1);
		i++;
	}
	else if (str[i] == '+')
	{
		turn_possitive = turn_possitive * 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * turn_possitive);
}

static int	get_total_length(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i < argc)
		len += ft_strlen(argv[i++]);
	return (len + (argc - 2) + 1);
}

char	*ft_strjoin(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		total_len;
	char	*result;

	i = 1;
	k = 0;
	total_len = get_total_length(argc, argv);
	result = malloc(total_len);
	if (!result)
		return (NULL);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			result[k++] = argv[i][j++];
		if (i != argc - 1)
			result[k++] = ' ';
		i++;
	}
	result[k] = '\0';
	return (result);
}
