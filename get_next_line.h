/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:59:02 by esellier          #+#    #+#             */
/*   Updated: 2024/02/23 16:57:42 by esellier         ###   ########.fr       */
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

char	*get_next_line(int fd);
char	*ft_stach_error(char **stach);
void	ft_buf_cpy(char **stach_ptr, char *buf, int readed);
int		ft_strlen(char *stach, int line);
char	*ft_end_stach(char **stach_ptr);
int		ft_search_line(char *stach);
char	*ft_substr(char **stach_ptr, int start);

#endif
