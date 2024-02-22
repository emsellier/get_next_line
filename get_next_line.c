/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:36 by esellier          #+#    #+#             */
/*   Updated: 2024/02/22 17:35:49 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_error(char *buf, char *stach)
{
	if (buf)
		free (buf);
	buf = NULL;
	if (stach)
		free (stach);
	stach = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stach;
	int			readed;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	readed = 0;
	if (ft_search_line(stach)) //--> ici car can on rappelle la fonction dans le main on checke d'abord si c'est une fin de ligne.
		return (ft_end_stach(&stach, readed));
	while (1)
	{
		buf = malloc(BUFFER_SIZE * sizeof(char));
		if (!buf)
			return (NULL);
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			return (ft_error(buf, stach));
		stach = malloc(ft_buf_cpy(stach, buf, readed) * sizeof (char));
		if (!stach)
			return (NULL);
		free (buf);
		//buf = NULL;
		//if (ft_search_line(stach)) //--> retourner la ligne + \n ou derniere ligne
		//	return (ft_end_stach(&stach, readed));
		if (!readed)
		{
			if (!stach)
				return (NULL);
			buf = ft_end_stach(&stach, readed);
			if (!buf)
				return (ft_error(buf, stach));
			stach = NULL; //--> pour ne pas avoir de boucle infini;
			return (buf);// --> j'utilise "buf" juste pour ne pas recreer une autre variable mais ce n'est pas le buffer 
		}
	}
	return (NULL);
}

#include <fcntl.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}