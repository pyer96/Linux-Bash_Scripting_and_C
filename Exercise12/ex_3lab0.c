#include<stdio.h>
#include<stdlib.h>


int main (int argc, char** argv){

	if(argc!=2) {
		dprintf(2,"BAD USAGE: a.out <integer>\n");
		return 1;
	}	
	for(int i= 0; i<atoi(argv[1]);i++){
		for(int j= 0; j<((*argv[1]-i)/2); j++){
				printf(" ");
			}	 
	for(int j=0; j<i+1;j++){
       			printf("*");
		}
	printf("\n");
	}

	return 0;
}


