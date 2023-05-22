#include "get_next_line.h"

char *read_save_modifid_and_send(int fd, char *temp);
char *rm_line(char *temp);

char *get_next_line(int fd)
{
    static char *temp;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    temp = read_save_modifid_and_send(fd, temp);
    line = send_line(temp);
    temp = rm_line(temp);
    //printf("-------line = %s\n", line);
    //printf("temp = %s\n", temp);
    return(line);
}

char *rm_line(char *temp)
{
    char *new_temp;
    int hin;
    int i;

    if(!temp)
        return NULL;
    hin = hin_bis_cut(temp);
    hin++;
    i = 0;
    new_temp = malloc(sizeof(char) * (ft_strlen(temp + hin) + 1));
    if(!new_temp)
        return NULL;

    while(temp[hin] != '\0')
    {
        new_temp[i] = temp[hin];
        i++;
        hin++;
    }
    new_temp[i] = 0;
    free(temp);
    return(new_temp);
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
    int read_check = 1;
    char *buff;
    //char *line;
    buff = malloc(sizeof(char) * 2);
    if(!buff)
        return NULL;
    //count = hin_bis_cut(temp);
   // printf("count = %d \n", count);
   //read_check = read(fd, buff, BUFFER_SIZE);
   //buff[read_check] = 0;
    buff[0] = ' ';
    while(read_check != 0 && buff[0])
    {
        read_check = read(fd, buff, 1);
        if(read_check == -1)
        {
            free(buff);
            return NULL;
        }
        buff[read_check] = '\0';
       // printf("buff = %s \n", buff);
        temp = ft_strjoin(temp, buff);
    }
    //printf("temp = %s\n", temp);
   // printf("line = %s", line);
    free(buff);
    return (temp);
}


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

