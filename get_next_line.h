/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:59:02 by esellier          #+#    #+#             */
/*   Updated: 2024/02/22 16:50:47 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char			*get_next_line(int fd);
char			*ft_error(char *buf, char *stach);
char			*ft_buf_cpy(char *stach, char *buf, int readed);
unsigned long	ft_strlen(char *stach, int line);
char			*ft_end_stach(char **stach, int readed);
int				ft_search_line(char *stach);
char			*ft_substr(char *stach, unsigned long start);

#endif