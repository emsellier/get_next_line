/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:57:11 by esellier          #+#    #+#             */
/*   Updated: 2024/02/21 21:46:51 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buf_cpy(char *stach, char *buf, int readed)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!readed)
		return (ft_error(buf, stach));
	if (stach)
		i = ft_strlen(stach, 0);
	tmp = malloc((readed + i + 1) * sizeof(char));
	if (!tmp)
		return (ft_error(buf, stach));
	i = 0;
	while (stach && stach[i] != '\0')
	{
		tmp[i] = stach[i];
		i++;
	}
	while (j < readed)
		tmp[i++] = buf[j++];
	tmp[i] = '\0';
	if (stach)
		free (stach);
	return (tmp);
}

unsigned long	ft_strlen(char *stach, int line)
{
	unsigned long	len;

	if (!stach)
		return (0);
	len = 0;
	if (line)
	{
		while (stach[len] != '\n' && stach[len] != '\0')
			len ++;
		return (len);
	}
	while (stach[len] != '\0')
		len++;
	return (len);
}

char	*ft_end_stach(char **stach_ptr) //--> pour pouvoir modifier la stach, il faut passer un pointeur sur stach, on traite la fin de ligne
{
	unsigned long	i;
	char			*tmp;
	char			*stach;

	stach = *stach_ptr;
	tmp = malloc((ft_strlen(stach, 1) + 2) * sizeof(char)); //-->chercher le premier \n
	if (!tmp)
		return (ft_error(NULL, stach));
	i = 0;
	while (stach[i] != '\n')
	{
		tmp[i] = stach[i];
		i++;
	}
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	*stach_ptr = ft_substr(stach, i + 1); //--> refaire une stach avec ce qui reste de la premiere ligne
	if (!*stach_ptr)
	{
		free (tmp);
		return (NULL);
	}
	return (tmp);
}

int	ft_search_line(char *stach)
{
	unsigned long		i;

	if (!stach)
		return (0);
	i = 0;
	while (stach[i] != '\n' && stach[i] != '\0')
		i++;
	if (stach[i] == '\n')
		return (1);
	return (0);
}

char	*ft_substr(char *stach, unsigned long start) //-->  copie une string + malloc et commence a l'index start ( pour garder les reste de cas de return)
{
	unsigned long	ls;
	char			*r;
	int				i;

	i = 0;
	ls = ft_strlen(stach, 0) - start + 1;
	r = malloc(ls * sizeof(char));
	if (!r)
		return (ft_error(NULL, stach));
	while (stach[start] != '\0')
		r[i++] = stach[start++];
	r[i] = '\0';
	free (stach);
	return (r);
}