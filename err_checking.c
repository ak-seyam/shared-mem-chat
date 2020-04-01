#include"err_checking.h"

void ERRCHECKER_shared_memory_getting(int id){
	if ( id < 0 )
	{
		perror("shared memory id couldn't be");
		exit(1);
	}
}
void ERRCHECKER_shared_memory_atteching(int pshared_memory){
	if ( pshared_memory  == -1 )
	{
		perror("couldn't attach that memory location");	
		exit(1);
	}
}
