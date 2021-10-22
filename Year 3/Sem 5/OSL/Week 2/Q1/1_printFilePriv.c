// Program to emulate the UNIX command : "ls -l"
// to list all files in the current directory and print their access privileges 

#include<stdio.h> 
#include<stdlib.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<string.h> 
#include<dirent.h> 

int main(){ 
	// importing our cwd and buffers
	DIR* d= opendir("/home/student/190905494/OS/Week 2/Q1");
	char* buff; 
	DIR* dad; 
	
	// checking to see if the entered directory is valid
	if(d==NULL) { 
		printf("Directory not accessible:\n"); 
		exit(0); 
	} 
	
	// structs
	struct dirent *item; 	// structure to hold information about a directory
	struct stat mystat; 	// struct to hold stats about a directory
	
	// iterating through each file in the cwd
	while((item=readdir(d))!=NULL){

		// getting the file permissions
		lstat(item->d_name,&mystat); 
		
		// checking to see if the selected object is either a file or a directory
		if(S_ISDIR(mystat.st_mode)){ 
			if(strcmp(".",item->d_name)==0 || strcmp("..",item->d_name)==0) 
				continue; 
			printf("d"); 
		} 
		else printf("-"); 
		
		// User, group and other perimissions 

		// user permissions
		if(mystat.st_mode & S_IRUSR){ 
			printf("r"); 
		} else printf("-"); 
		
		if(mystat.st_mode & S_IWUSR){ 
		printf("w"); 
		} else printf("-"); 
		
		if(mystat.st_mode & S_IXUSR){ 
		printf("x"); 
		} else printf("-"); 
		

		// group permissions
		if(mystat.st_mode & S_IRGRP){ 
		printf("r"); 
		} else printf("-"); 
		
		if(mystat.st_mode & S_IWGRP){ 
		printf("w"); 
		} else printf("-"); 
		
		if(mystat.st_mode & S_IXGRP){ 
		printf("x"); 
		} else printf("-"); 
		

		// other permissions
		if(mystat.st_mode & S_IROTH){ 
		printf("r"); 
		} else printf("-"); 
		
		if(mystat.st_mode & S_IWOTH){ 
		printf("w"); 
		} else printf("-"); 
		
		if(mystat.st_mode & S_IXOTH){ 
		printf("x\t"); 
		} else printf("-\t"); 
		

		// Handling a Directory(2) or File(1) 
		if(S_ISDIR(mystat.st_mode)){ 
		printf("2\t"); 
		} else printf("1\t"); 
		
		// getting and printing login buffer
		buff = getlogin(); 
		printf("%s\t",buff); 

		// Printing the Name of item in consideration 
		printf("%s\n",item->d_name); 
	} 
} 