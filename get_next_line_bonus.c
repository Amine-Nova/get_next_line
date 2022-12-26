/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:40:37 by abenmous          #+#    #+#             */
/*   Updated: 2022/11/15 10:26:56 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_read(int fd, char *line)
{
	char	str[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	str[0] = 0;
	while (!(ft_strchr(str, '\n')) && i > 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		str[i] = '\0';
		if (i > 0)
			line = ft_strjoin(line, str);
	}
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_plus(char *str)
{
	int		i;
	int		j;
	char	*ss;
	int		len;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || (str[i] == '\n' && str[i + 1] == 0))
	{
		free(str);
		return (0);
	}
	i++;
	len = ft_strlen(str) - i + 1;
	ss = malloc(len + 1);
	j = 0;
	while (str[i])
		ss[j++] = str[i++];
	ss[j] = 0;
	free (str);
	return (ss);
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*str[OPEN_MAX];

	if (fd < 0 || fd == 1 || fd == 2)
		return (0);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (0);
	s = ft_strdup(str[fd]);
	str[fd] = ft_plus(str[fd]);
	return (s);
}
