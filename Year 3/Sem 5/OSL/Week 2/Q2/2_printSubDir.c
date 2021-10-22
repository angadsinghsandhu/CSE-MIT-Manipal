// Program to list all files in cwd and its sub directories

#include<stdio.h> 
#include<stdlib.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<string.h> 
#include<dirent.h> 

// function to traverse the directory
void function(char* dir, int depth){ 

	// insitializig our variables or hadnling files in LINUX
	DIR* d; struct 
	dirent* item; 
	struct stat mystat; 
	
	// check to see if directory exists
	if((d=opendir(dir))==NULL){ 
		printf("Directory isn't opening: %s\n", dir); 
 		return; 
	}

	// changing our cwd to the location mentioned int he function
 	chdir(dir); 

 	// iterating through all items in our directory
 	while((item = readdir(d))!=NULL){

 		// getting a storing permissions in mystat
		lstat(item->d_name,&mystat); 

		// checking to see if we have a file or directory
		if(S_ISDIR(mystat.st_mode)){ 

			// for files
			if(strcmp(".",item->d_name)==0 || strcmp("..",item->d_name)==0)
				continue; 

			// for dirs by recursive call
			printf("%*s%s/\n",depth,"",item->d_name); function(item->d_name,depth+4); 

		} else printf("%*s%s/\n",depth,"",item->d_name); 
	} 

	// going back to upper dir
	chdir(".."); 
	closedir(d); 
} 

// DRIVER CODE
int main(){ 
	// Listing our cwd and depth of traversal
	function("/home/student/190905494/OS/Week 2/Q2",0); 
	exit(0); 
}