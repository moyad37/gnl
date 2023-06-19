/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/19 11:28:47 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	hin_bis_cut(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*send_line(char *temp)
{
	char	*line;
	int		z;
	int		hin;

	z = 0;
	if (!temp[z])
		return (NULL);
	hin = hin_bis_cut(temp);
	line = malloc_and_check((hin + 2), sizeof(char));
	while (temp[z] != '\0' && temp[z] != '\n')
	{
		line[z] = temp[z];
		z++;
	}
	if (temp[z] == '\n')
		line[z++] = '\n';
	line[z] = 0;
	return (line);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*my;

	my = (char *)s;
	while (*my != c && *my != 0)
	{
		my++;
	}
	if (*my == c)
		return (my);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	z;
	char	*my_str;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	i = 0;
	z = 0;
	my_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!my_str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		my_str[i] = s1[i];
		i++;
	}
	while (z < ft_strlen(s2))
		my_str[i++] = s2[z++];
	my_str[i] = 0;
	free(s1);
	return (my_str);
}
