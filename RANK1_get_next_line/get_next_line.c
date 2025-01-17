/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leiwang <leiwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:02:16 by leia              #+#    #+#             */
/*   Updated: 2024/09/23 17:04:23 by leiwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static int	handle_read(int fd, char *buffer, char **buff_holder)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		ft_free((void **)buff_holder);
		return (-1);
	}
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

static char	*get_line_with_backslash_n(int fd, char *buffer, char **buff_holder)
{
	int		bytes_read;
	char	*temp;

	while (1)
	{
		bytes_read = handle_read(fd, buffer, buff_holder);
		if (bytes_read <= 0)
			break ;
		if (!(*buff_holder))
		{
			*buff_holder = ft_strdup("");
			if (!(*buff_holder))
				return (NULL);
		}
		temp = *buff_holder;
		*buff_holder = ft_strjoin(temp, buffer);
		ft_free((void **)&temp);
		if (!(*buff_holder))
			return (NULL);
		if (ft_strchr(*buff_holder, '\n'))
			break ;
	}
	return (*buff_holder);
}

static char	*extract_line(char **buff_holder)
{
	size_t	i;
	char	*remainder;

	i = 0;
	if ((*buff_holder)[i] == '\0')
		return (NULL);
	while ((*buff_holder)[i] != '\n' && (*buff_holder)[i] != '\0')
		i++;
	remainder = ft_substr(*buff_holder, i + 1, ft_strlen(*buff_holder) - i);
	if (!remainder)
		return (NULL);
	if (remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	if ((*buff_holder)[i])
		(*buff_holder)[i + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*buff_holder;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX || fd > 1024)
	{
		ft_free((void **)&buff_holder);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = get_line_with_backslash_n(fd, buffer, &buff_holder);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		ft_free((void **)&buff_holder);
		return (NULL);
	}
	buff_holder = extract_line(&buff_holder);
	return (line);
}

// int	main(void)
// {
// 	int fd;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	char *read_1 = get_next_line(fd);
// 	printf("HELLO WHEN WE ONLY READ ONCE: %s", read_1);

// 	char *read_2 = get_next_line(fd);
// 	printf("HELLO WHEN WE READ Second time: %s", read_2);

// 	close(fd);
// 	return (0);
// }
