/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grinella <grinella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:24:09 by grinella          #+#    #+#             */
/*   Updated: 2023/02/27 15:50:48 by grinella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strdup(const char *s1);
unsigned int	ft_strlen(const char *s);
int				ft_putindex(const char *s, char c);

#endif
