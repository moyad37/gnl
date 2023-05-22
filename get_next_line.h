#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
int hin_bis_cut(char *str);
size_t ft_strlen(char *str);
char *ft_strjoin(char *s1, char *s2);
char *ft_strchr(char *s, int c);
//char	*ft_strchr2(char *s, int c);
char    *send_line(char *temp);


