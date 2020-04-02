#include"err_checking.h"
#include<stdio.h>
#include <stdlib.h>

void ERRCHECKER_shared_memory_getting(int id){
	if ( id < 0 )
	{
		perror("shared memory id couldn't be");
		exit(1);
	}
}
void ERRCHECKER_shared_memory_atteching(char *pshared_memory){
	if ( *pshared_memory  == -1 )
	{
		perror("couldn't attach that memory location");	
		exit(1);
	}
}
