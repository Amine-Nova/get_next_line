/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:42:49 by abenmous          #+#    #+#             */
/*   Updated: 2022/11/14 16:10:12 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

void	*my_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	len;
	size_t	i;	

	len = count * size;
	str = malloc(len);
	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str3;

	i = -1;
	j = 0;
	if (!str1 && !str2)
		return (0);
	if (!str1)
		str1 = my_calloc(1, 1);
	str3 = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str3)
	{
		free(str1);
		return (0);
	}
	while (str1 && str1[++i])
		str3[i] = str1[i];
	while (str2[j])
		str3[i++] = str2[j++];
	str3[i] = '\0';
	free(str1);
	return (str3);
}

char	*ft_strchr(char *s, int c)
{
	char	y;
	int		i;

	i = 0;
	y = (char )c;
	while (s && s[i])
	{
		if (s[i] == y)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src1)
{
	int		u;
	char	*src2;

	if (!src1)
		return (NULL);
	u = 0;
	while (src1[u] && src1[u] != '\n')
		u++;
	src2 = malloc(u + 2);
	if (!src2)
		return (NULL);
	u = 0;
	while (src1[u] && src1[u] != '\n')
	{
		src2[u] = src1[u];
		u++;
	}
	if (src1[u] == '\n')
		src2[u++] = '\n';
	src2[u] = '\0';
	return (src2);
}
