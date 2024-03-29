/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:36 by esellier          #+#    #+#             */
/*   Updated: 2024/02/26 16:24:13 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stach_error(char **stach)
{
	if (*stach)
	{
		free (*stach);
		*stach = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stach;
	int			readed;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE < 1)
		return (NULL);
	if (ft_search_line(stach))
		return (ft_end_stach(&stach));
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (ft_stach_error(&stach));
	readed = read(fd, buf, BUFFER_SIZE);
	if (readed > 0)
	{
		ft_buf_cpy(&stach, buf, readed);
		free (buf);
		if (!stach)
			return (NULL);
		return (get_next_line(fd));
	}
	free (buf);
	if (readed < 0 || !stach || ft_strlen(stach, 0) == 0)
		return (ft_stach_error(&stach));
	return (ft_sub_stach(&stach, 0));
}

/*#include <fcntl.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			return (0);
		printf("%s", line);
		free(line);
	}
	return (0);
}*/