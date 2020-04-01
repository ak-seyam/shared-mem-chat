#include"messeging.h"

#define ENDING_CHAR '\n'

void send_messege(char *messege, char *shm){
	int messege_length = strlen(messege);
	// copy a message to the shared memory
	memcpy(shm,messege,messege_length*sizeof(char)); // now shm points to a string equals message

	// add a '\0' to the string to make it a proper one
	/*shm += 11; // move 11 steps now shm is right after the hello world thing*/
        *(shm+messege_length) = '\0';
}

void reciving(char *shm){
	// traverse throgh the string pointing to by the shared memory pointer
	for( char *message = shm; *message != '\0' ; message++)
	{
		printf("%c", *message);
		*message = '\0'; // cleaning the buffer
	}

	printf("\n");
	*shm = ENDING_CHAR;
}
void stall(char *shm){
	while (*shm != ENDING_CHAR) // stall and clear
	{
		sleep(1);
	}
	*shm = '\0';
}
