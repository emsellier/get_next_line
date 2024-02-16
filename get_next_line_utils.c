/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:57:11 by esellier          #+#    #+#             */
/*   Updated: 2024/02/16 17:19:22 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ssize_t	read(int fd, void *buf, size_t buffer_size)
unsigned long	ft_buf_cpy(char *stach, char *buf, size_t buffer_size)
{
	unsigned long	i;
	unsigned long	j;

	i = ft_strlen(stach);
	if (stach != NULL)
	{
		i++; //--> pour que si c'est les premiers caracteres i commence a zero et ici a +1
		free (stach); //--> mais ca vide ce qu'il y a deja dedans?
		stach = malloc(i + buffer_size * sizeof (char));
		if (!stach)
			return (0); //si NULL ne compile pas
	}
	j = 0;
	while (j <= buffer_size && buffer_size > 0 && stach[i] && buf[i])
	{
		stach[i] = buf[j];
		i++;
		j++;
	}
	if (buf[i] == '\n')
		stach[i] = buf[j];
	return (buffer_size);
}

unsigned long	ft_strlen(char *stach)
{
	unsigned long	len;

	len = 0;
	while (stach[len] != '\n' || stach[len] != '\0')
		len ++;
	return (len);
}

/*unsigned long	ft_join_stach(char *stach, char *buf, size_t buffer_size)
{
	unsigned long	i;

	i = 0;
	if (stach[i])
		i++;
	if (buf && i > 0)
		ft_buf_cpy(stach, buf, i, buffer_size);
	return (0);
}*/

void	*ft_clean_stach(char *stach, size_t buffer_size)
{
	size_t	i;

	i = 0;
	while (i < buffer_size)
	{
		stach[i] = '\0';
		i++;
	}
	return(0);
}

void	ft_put_buf(char *stach, char *buf, size_t buffer_size)
{
	unsigned long	i;
	unsigned long	j;

	j = 0;
	while (buf[j] != '\n')
		j++;
	i = 0;
	if (buf[j] == '\n')
	{
		j++;
		while (j < buffer_size)
		{
			stach[i] = buf [j];
			i++;
			j++;
		}
	}
	return ;
}
int ft_search_line(char *stach)
{
	char	c;
	int		i;
	
	c = '\n'
	i = 0;
	while (stach [i] != '\n' && stach[i] != '\0')
		i++;
	if (stach[i] == '\n')
		return (1);
	return (0);
}