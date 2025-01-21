/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leia <leia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:00:57 by leiwang           #+#    #+#             */
/*   Updated: 2025/01/20 23:40:02 by leia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_is_digit(char c);
int is_integer(int ac, char **av);
int is_not_dup(int ac, char **av);
int is_within_limits(int ac, char **av);
int ft_strcmp(char *s1, char *s2);

typedef struct s_stack
{
	int data;
	struct s_stack *next;
} t_stack;


#endif

