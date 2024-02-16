/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:36 by esellier          #+#    #+#             */
/*   Updated: 2024/02/16 16:41:21 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void		*buff;
	char		*buf;
	static char	*stach;
	size_t		buffer_size;
	
	buff = NULL;
	buffer_size = 5;
	while (stach) //(stach[] != '\n')
	{
		if ((read(fd, buff, buffer_size) == -1) || (read(fd, buff, buffer_size) == 0) || (!fd))
			return (NULL);
		buf = malloc(buffer_size * sizeof (char));
		if (!buf || buffer_size < 1)
			return (NULL);
		stach = malloc(buffer_size + 1 * sizeof (char)); // --> creer la static avec la taille de la ligne
		if (!stach)
			return (NULL);
		if (ft_buf_cpy(stach, buf, buffer_size) == 0) //  --> mettre le buf dans le static
			return (NULL);
	}	
	if (ft_search_line(stach) == 1) //--> mettre la 1ere ligne + \n
	{
		return (stach);
		ft_clean_stach(stach, buffer_size); //-->	nettoyer stach avant le \n;
		ft_put_buf(stach, buf, buffer_size); // --> copier ce qui reste du buffer
	}
	if (get_next_line(fd) == NULL) //--> on recommence a la ligne d'apres
		return (NULL);
	free (stach);
	free (buf);
	return (NULL);
}
// comment gerer la derniere ligne?
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
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
//faire plein de test de taille de buffer surtout si il fait 10 000.
