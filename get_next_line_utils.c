#include "get_next_line.h"


int hin_bis_cut(char *str)
{
    int i = 0;
    if(!str)
        return 0;
    while(str[i] && str[i] != '\n' && str[i] != '\0')
        i++;
    return(i);
}
/////////////////////////////////////////////////////////
char    *send_line(char *temp)
{
    char *line;
    int z;
    int hin;

    z = 0;
    hin = hin_bis_cut(temp);
    line = malloc(sizeof(char) * (hin + 2));
    if(!line)
    {
        free(temp);
        return (NULL);
    }
    while(temp[z] != '\0' && temp[z] != '\n')
    {
        line[z] = temp[z];
        z++;
    }
    line[z++] = '\n';
    line[z] = 0; 
    return(line);
    // char	*line;
	// int		i;

	// i = 0;
	// if (!temp[i])
	// 	return (NULL);
	// while (temp[i] && temp[i] != '\n')
	// 	i++;
	// line = malloc(sizeof(char) * (i + 2));
	// if (!line)
	// 	return (NULL);
	// i = 0;
	// while (temp[i] && temp[i] != '\n')
	// {
	// 	line[i] = temp[i];
	// 	i++;
	// }
	// if (temp[i] == '\n')
	// {
	// 	line[i] = temp[i];
	// 	i++;
	// }
	// line[i] = '\0';
	// return (line);
}

size_t ft_strlen(char *str)
{
    size_t i = 0;
    while (str[i])
        i++;
    return(i);
}
/*
char *ft_strchr(char *s, int c)
{
    if(!s)
    {
        return(0);
    }
    if(c == '\0')
        return(0);
    while(*s++ != (char) c)
        if(*s == (char)c )
            return(s);
    return (0);

}
*/

//////////////////////////////////////////////

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *my_text;

    if(!s1)
    {
        s1 = malloc(1);
        if(!s1)
            return NULL;
        s1[0] = 0;
    }
    if(!s2)
        return(NULL);
    my_text = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if(!my_text)
        return(NULL);
    while(s1[i] != '\0')
    {
        my_text[i] = s1[i];
        i++;
    }
    while(s2[j])
        my_text[i++] = s2[j++];
    my_text[i] = '\0';
    free(s1);
    return(my_text);
    // 	int		i;
	// int		z;
	// char	*my;

	// if (!s1)
	// {
	// 	s1 = malloc(1);
	// 	s1[0] = '\0';
	// }
	// if (!s2)
	// 	return (NULL);
	// my = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	// if (!my)
	// 	return (NULL);
	// i = -1;
	// while (s1[++i] != '\0')
	// 	my[i] = s1[i];
	// z = 0;
	// while (s2[z] != '\0')
	// 	my[i++] = s2[z++];
	// my[i++] = '\0';
	// free(s1);
	// return (my);
}
/*
int main()
{
  printf("%d \n",  printf("%s \n", ft_strchr("Hallo my j\nj", '\n')));
  printf("-----------");
  printf("%d",  printf("%s \n", ft_strchr2("Hallo my j\nj", '\n')));

}
*/