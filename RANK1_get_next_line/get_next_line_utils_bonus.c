/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:54:26 by leia              #+#    #+#             */
/*   Updated: 2024/09/22 18:22:10 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return (&tmp[i]);
		i++;
	}
	if (tmp[i] == (char)c)
		return (&tmp[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new_s == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		new_s[i + j] = s1[j];
		j++;
	}
	while (s2[k] != '\0')
	{
		new_s[i + j + k] = s2[k];
		k++;
	}
	new_s[i + +j + k] = '\0';
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i = i + 1;
	ptr = (char *)malloc(sizeof(char) * i + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	return (ptr);
}
