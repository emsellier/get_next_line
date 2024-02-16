/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:59:02 by esellier          #+#    #+#             */
/*   Updated: 2024/02/15 19:08:17 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
unsigned long	ft_buf_cpy(char *stach, char *buf, size_t buffer_size);
unsigned long	ft_strlen(char *str);
unsigned long	ft_join_stach(char *stach, char *buf, size_t buffer_size);
void	*ft_clean_stach(char *stach, size_t buffer_size);
void	ft_put_buf(char *stach, char *buf, size_t buffer_size);

#endif
