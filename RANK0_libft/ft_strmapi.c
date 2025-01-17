/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:53:50 by leia              #+#    #+#             */
/*   Updated: 2024/08/12 19:45:04 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_len;
	char	*result;

	i = 0;
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

char ft_toupper1(unsigned int index, char c) {
	(void) index;
    if ('a' <= c && c <= 'z') {
        return (c - 32);  // 转换为大写
    }
    return (c);  // 非小写字母字符不变
}

int main(void) {
    char s[] = "hello world";
    int i = 0;

    // 调用 ft_strmapi 函数
    char *result = ft_strmapi(s, ft_toupper1);

    // 打印结果
    if (result != NULL) {
        printf("Output: %s\n", result);
    free(result);  // 记得释放内存
    }
    return (0);
}
