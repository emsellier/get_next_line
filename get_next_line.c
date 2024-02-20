/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:36 by esellier          #+#    #+#             */
/*   Updated: 2024/02/20 17:12:28 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stach;
	int			readed;
	char*		line;

	if (fd < 1 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	if (ft_search_line(stach) == 0)
	{
			readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 1)
			return (NULL);
		stach = ft_buf_cpy(stach, buf, readed);
		if (!stach)
			return (NULL);
	}
	printf("%s\n", "test");
	if (ft_search_line(stach) == 1) //--> mettre la 1ere ligne + \n
	{
		printf("%s\n", "test2");
		line = ft_end_stach(stach); // --> garder ce qu'il y a apres le \n dans la stach et revoyer la temporaire ace le pre;eiere ligne
		printf("%s\n", "test3");
		return (line);
	}
	free (buf);
	if (get_next_line(fd) == NULL) //--> on recommence a la ligne d'apres
		return (NULL);
	free (stach);
	printf("%s\n", "test4");
	return (NULL);
}
#include <fcntl.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	/*while (1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			return (0);
		printf("%s", line);
		free(line);
	}*/
	line = get_next_line(fd);
	printf("Result:%s", line);
	line = get_next_line(fd);
	printf("Result:%s", line);

	return (0);
}
//faire plein de test de taille de buffer surtout si il fait 10 000.
