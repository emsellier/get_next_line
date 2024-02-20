/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:57:11 by esellier          #+#    #+#             */
/*   Updated: 2024/02/20 17:15:21 by esellier         ###   ########.fr       */
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
	if (stach)
		i = ft_strlen(stach);
	tmp = malloc((readed + i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
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
	{
		free (stach);
		stach = NULL;
	}
	stach = tmp; // ca suffit pour copier le tmp? pas besoin de malloc la stach?
	tmp = NULL;
	free (tmp); //fait planter la compilation si il n'y a pas la ligne du dessus, mais resultat egale sans ces deux lignes)
	return (stach);
}
unsigned long	ft_strlen(char *stach)
{
	unsigned long	len;

	len = 0;
	while (stach[len] != '\n' && stach[len] != '\0')
		len ++;
	return (len);
}
char	*ft_end_stach(char *stach)
{
	unsigned long	i;
	unsigned long	j;
	char	*tmp;

	j = 0;
	i = ft_strlen(stach); //--> calculer jusqu'au \n
	tmp = (char *)malloc((i + 2) * sizeof(char));
	i = 0;
	if (stach[j] != '\n')
		tmp[i++] = stach[j++];
	tmp[i] = '\n';
	tmp[i + 1] = '\0'; //--> copier le debut dans la tmp et renvoyer la ligne
	stach = ft_substr(stach, i); //--> refaire une stach avec ce qui reste de la premiere ligne
	return (tmp); 
}
int ft_search_line(char *stach)
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
char	*ft_substr(char *stach, unsigned long start)
{
	unsigned long	ls;
	char	*r;

	ls = ft_strlen(stach) - start + 1;
	r = malloc(ls * sizeof(char));
	if (!r)
		return (NULL);
	while (stach[start] != '\0')
	{
		r[start] = stach[start];
		start++;
	}
	r[start] = '\0';
	return (r);
}