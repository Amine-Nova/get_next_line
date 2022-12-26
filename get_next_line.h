/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:06:31 by abenmous          #+#    #+#             */
/*   Updated: 2022/11/15 11:16:09 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4

# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0

# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *src1);
char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlen(char *s);
char	*ft_read(int fd, char *line);
char	*ft_plus(char *str);
char	*ft_strchr(char *s, int c);
void	*my_calloc(size_t count, size_t size);

#endif
