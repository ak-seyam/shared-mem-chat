#include"messaging.h"
#include <unistd.h>
#include<string.h>
#define ENDING_CHAR '\n'


void send_message(char *sender, char *message, char *shm){
	char sent_message[strlen(message)+strlen(sender)+20];
	sprintf(sent_message,"%s: %s",sender,message);
	printf("%s\n", sent_message);
       	int message_length = strlen(sent_message); 
	// copy a message to the shared memory
	memcpy(shm,sent_message,message_length*sizeof(char)); // now shm points to a string equals message

	// add a '\0' to the string to make it a proper one
	/*shm += 11; // move 11 steps now shm is right after the hello world thing*/
        *(shm+message_length) = '\0';
	stall(shm);
	sleep(1);
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
	sleep(1);
}
void stall(char *shm){
	while (*shm != ENDING_CHAR) // stall and clear
	{
		sleep(1);
	}
	*shm = '\0';
}
