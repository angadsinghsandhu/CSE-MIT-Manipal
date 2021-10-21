#include<stdio.h> 
#include<stdlib.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<string.h> 
#include<dirent.h> 
int main(){ 
DIR* d= opendir("/home/student/Documents/190905076/OSL/L1"); 
char* buff; 
DIR* dad; 
if(d==NULL) { printf("Directory 
not accessible:\n"); 
exit(0); 
} 
struct dirent *item; 
struct stat mystat; 
//struct tm *foo; 
//foo = gmtime(mystat.st_mtime); 
while((item=readdir(d))!=NULL){ 
lstat(item->d_name,&mystat); 
//d or -
if(S_ISDIR(mystat.st_mode)){ if(strcmp(".",item->d_name)==0 || 
strcmp("..",item->d_name)==0) continue; 
printf("d"); 
} 
else printf("-"); 
//User, group and other perimissions 
if(mystat.st_mode & S_IRUSR){ 
printf("r"); 
} 
else printf("-"); 
if(mystat.st_mode & S_IWUSR){ 
printf("w"); 
} 
else printf("-"); 
if(mystat.st_mode & S_IXUSR){ 
printf("x"); 
} 
else printf("-"); 
if(mystat.st_mode & S_IRGRP){ 
printf("r"); 
} 
else printf("-"); 
if(mystat.st_mode & S_IWGRP){ 
printf("w"); 
} 
else printf("-"); 
if(mystat.st_mode & S_IXGRP){ 
printf("x"); 
} 
else printf("-"); 
if(mystat.st_mode & S_IROTH){ 
printf("r"); 
} 
else printf("-"); 
if(mystat.st_mode & S_IWOTH){ 
printf("w"); 
} 
else printf("-"); 
if(mystat.st_mode & S_IXOTH){ 
printf("x\t"); 
} 
else printf("-\t"); 
//Directory or File 
if(S_ISDIR(mystat.st_mode)){ 
printf("2\t"); 
} 
else printf("1\t"); 
buff = getlogin(); 
printf("%s\t",buff); 
//Name of item in consideration 
printf("%s\n",item->d_name); 
} 
} 