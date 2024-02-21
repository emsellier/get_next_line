/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:55:36 by esellier          #+#    #+#             */
/*   Updated: 2024/02/21 21:46:44 by esellier         ###   ########.fr       */
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
/*char	*ft_check_last_line(char *buf, char *stach)
{
	char		*tmp;
	unsigned long	i;
	unsigned long	j;

	//if (!buf)
	//	return (NULL);
	if (!stach)
		return(buf);
	else
	{
		tmp = malloc((ft_strlen(buf, 0) + ft_strlen(stach, 0) + 2) * sizeof(char));
		if (!tmp)
			return (ft_error(buf, stach));
		i = 0;
		j = 0;
		while (i < ft_strlen(stach, 0))
			tmp[j++] = stach[i++];
		i = 0;
		while (i < ft_strlen(buf, 0))
			tmp[j++] = buf[i++];
		tmp[j + 1] = '\0';
		ft_error(buf, stach);
		return (tmp);
	}
	return (0);
}*/

/*char	*ft_check_last_line(char *stach)
{
	if (!stach)
		return(NULL);
	else
		return (stach);
}*/

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stach;
	int			readed;
	
	if (fd < 1 || BUFFER_SIZE < 1)
		return (NULL);
	if (ft_search_line(stach)) //--> pk ici ???? sans c une ligne en moins quand je print
		return (ft_end_stach(&stach));
	while(1)
	{
		buf = malloc(BUFFER_SIZE * sizeof(char));
		if (!buf)
			return (NULL);
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
			return (ft_error(buf, stach));
		stach = ft_buf_cpy(stach, buf, readed);
		if (!stach)
			return (NULL);
		free (buf);
		buf = NULL;
		if (ft_search_line(stach)) //--> mettre la 1ere ligne + \n
			return (ft_end_stach(&stach));
		//if (!readed)
		//{
			//if (!stach)
			//	return (NULL);
			///buf = ft_check_last_line(stach);
			//if (!buf)
			//	return (ft_error(buf, stach));
			//stach = NULL; //--> pour ne pas avoir de boucle infini;
			//return (buf);// --> j'utilise "buf" juste pour ne pas recreer une autre variable mais ce n'est pas le buffer 
		if (!readed && stach && *stach)
			return (ft_end_stach(&stach));
		if (!readed && (!stach || !*stach))
			return(NULL);
	}
	return(NULL);
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
//faire plein de test de taille de buffer surtout si il fait 10 000.
