#include "get_next_line.h"

char *read_save_modifid_and_send(int fd, char *temp);
char *rm_line(char *temp);

char *get_next_line(int fd)
{
    static char *temp;
    char *line;

    line = NULL;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    temp = read_save_modifid_and_send(fd, temp);
    if(!temp)
        return (NULL);
    line = send_line(temp);
    temp = rm_line(temp);
    return(line);
}
///////////////////MEMORY LEADKS /////////////////////////
char *rm_line(char *temp)
{
    // char *new_temp;
    // int hin;
    // int i;

    // if(!temp)
    //     return NULL;
    // hin = hin_bis_cut(temp);
    // hin++;
    // i = 0;
    // new_temp = malloc(sizeof(char) * (ft_strlen(temp + hin) + 1));
    // if(!new_temp)
    //     return NULL;

    // while(temp[hin] != '\0')
    // {
    //     new_temp[i] = temp[hin];
    //     i++;
    //     hin++;
    // }
    // new_temp[i] = 0;
    // free(temp);
    // return(new_temp);
    	char	*modifidet_temp;
	int		i;
	int		z;

	i = 0;
	z = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	modifidet_temp = malloc(ft_strlen(temp + ++i) + 1);
	if (!modifidet_temp)
		return (NULL);
	while (temp[i])
		modifidet_temp[z++] = temp[i++];
	modifidet_temp[z] = '\0';
	free(temp);
	return (modifidet_temp);
}

/*
void check_null(char *temp)
{
    int i = 0;
    while (temp[i] != '\0')
    {
        printf("%c", temp[i]);
        i++;
    }
    printf("\n");
    printf("len = %d\n", i);
    if(temp[i] == '\0')
    {
        printf("\n Ich habe einen NULL gefunden\n");
    }
}
*/
char *read_save_modifid_and_send(int fd, char *temp)
{
    int read_check;
    char *buff;
    //char *line;

    read_check = 1;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buff)
        return NULL;
    buff[0] = ' ';
    while(read_check != 0 && !ft_strchr(temp, '\n'))
    {
        read_check = read(fd, buff, BUFFER_SIZE);
        if(read_check == -1)
        {
            free(buff);
            return NULL;
        }
        buff[read_check] = '\0';
        temp = ft_strjoin(temp, buff);
    }
    free(buff);
    return (temp);
}

/*
int main(void)
{
    char *filename = "hub.txt";
    int fd;
    char		*dst;

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
    
    return 0;
}
*/


