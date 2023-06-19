/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/19 11:28:42 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_save_modifid_and_send(int fd, char *temp);
char	*rm_line(char *temp);

char	*get_next_line(int fd)
{
	static char	*temp[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	temp[fd] = read_save_modifid_and_send(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = send_line(temp[fd]);
	temp[fd] = rm_line(temp[fd]);
	return (line);
}

char	*rm_line(char *temp)
{
	char	*new_temp;
	int		hin;
	int		i;

	i = 0;
	hin = 0;
	hin = hin_bis_cut(temp);
	if (!temp[hin])
	{
		free(temp);
		return (NULL);
	}
	hin++;
	new_temp = malloc_and_check((ft_strlen(temp + hin) + 1), sizeof(char));
	while (temp[hin] != '\0')
	{
		new_temp[i] = temp[hin];
		i++;
		hin++;
	}
	new_temp[i] = 0;
	free(temp);
	return (new_temp);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*malloc_and_check(size_t count, size_t size)
{
	char	*result;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, (size * count));
	return (result);
}

char	*read_save_modifid_and_send(int fd, char *temp)
{
	int		read_check;
	char	*buff;

	buff = malloc_and_check((BUFFER_SIZE + 1), 1);
	read_check = 1;
	while (read_check > 0)
	{
		read_check = read(fd, buff, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_check] = '\0';
		temp = ft_strjoin(temp, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (temp);
}

/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}



void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while ((line = get_next_line(fd)))
	{
		ft_putendl_fd(line, 1);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
*/
/*
int	main(void)
{
	char	*filename;
    int fd;
    char		*dst;

    filename = "hub.txt";
    fd = open(filename, O_RDONLY);
    //printf(" fd = %d \n", fd);
    
    fd = open(filename, O_RDONLY);
	dst = get_next_line(fd);
    printf("%s\n", dst);
    free(dst);
    dst = get_next_line(fd);
    printf("%s\n", dst);
    free(dst);
    dst = get_next_line(fd);
    printf("%s\n", dst);
    free(dst);
    dst = get_next_line(fd);
    printf("%s\n", dst);
    free(dst);
    
    return (0);
}

*/
