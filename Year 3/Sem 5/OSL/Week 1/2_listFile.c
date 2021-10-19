// Write a program to list the files given as arguments, stopping every 20 lines
// until a key is hit. (a simple version of more UNIX utility)


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int sfd, sfd2, i = 0, j = 0, k = 0;
    char s[100], s2[100], c;
    
    
    if(argc != 3)
    {
        printf("Arguments less than 3\n");
        exit(1);
    }

    
    if((sfd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("File cannot be opened\n");
        exit(1);
    }

    while((read(sfd,&c,1)) > 0)
    {
        if(c != '\n')
        {
            s[i] = c;
            i++;
        }
        else
        {
            j++;
            k++;
            s[i] = '\0';
            i = 0;
            printf("Line: %d \t %s \n", k, s);
            if(j == 20)
            {
                // gets next character 
                fgetc(stdin);
                j = 0;
            }
        }
    }
    close(sfd);

    
    if((sfd2 = open(argv[2], O_RDONLY)) == -1)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    k = 0;

    while((read(sfd, &c, 1))>0)
    {
        if(c != '\n')
        {
            s2[i] = c;
            i++;
        } 
        else
        {
            j++;
            k++;
            s2[i] = '\0';
            i = 0;
            printf("l: %d \t %s \n", k, s2);
            if(j == 20)
            {
                
                fgetc(stdin);
                j = 0;
            }
        }
    }
    exit(0);
}
