// Write a program to print the lines of a file that contain a word given as the
// program argument (a simple version of grep UNIX utility).

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[]) {
	int fd;
	int i=0;
	int k=0;
	char ch[100];

	char chr;

	if(argc!=3) {
		printf("Insufficient arguments");
		exit(1);

	}

	if(fd=(open(argv[2],O_RDONLY))==-1)
	{
		printf("File is not there");
		exit(1);
	}

	while((read(fd,&chr,1))>0) {
		if(chr!='\n') {
			ch[i]=chr;
			i++;
		}

		else {
			k++;
			ch[i]='\0';
			i=0;
			if(strstr(ch,argv[1])!=NULL) {
				printf("Line: %d\t %s\n",k,ch);
			}
		}
	}
	exit(0);
}
