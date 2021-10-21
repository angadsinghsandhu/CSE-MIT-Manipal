#include<stdio.h> 
#include<stdlib.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<string.h> 
#include<dirent.h> 
void function(char* dir, int depth){ DIR* d; struct 
dirent* item; struct stat mystat; 
if((d=opendir(dir))==NULL){ 
fprintf(stderr,"Directory isn't opening:\n",dir); 
 return; 
} 
 chdir(dir); while((item = 
readdir(d))!=NULL){ 
 lstat(item->d_name,&mystat); 
 if(S_ISDIR(mystat.st_mode)){ if(strcmp(".",item-
>d_name)==0 || strcmp("..",item->d_name)==0){ 
 continue; 
} 
 printf("%*s%s/\n",depth,"",item->d_name); function(item-
>d_name,depth+4); 
 } 
 else printf("%*s%s/\n",depth,"",item->d_name); 
 } 
 chdir(".."); 
closedir(d); 
} 
int main(){ function("/mnt/c/Users/steph/Documents/190905076_OSLAB",0); 
exit(0); 
}