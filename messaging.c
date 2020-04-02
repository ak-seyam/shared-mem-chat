#include"messaging.h"
#include <unistd.h>
#include<string.h>


void send_message(char *sender, char *message, char *shm){
	/*printf("log: session opened\n");*/
	printf("-----------\n");
	*shm = '*';
	stall('#',shm);
	char sent_message[strlen(message)+strlen(sender)+20];
	sprintf(sent_message,"%s: %s",sender,message);
	printf("%s\n", sent_message);
       	int message_length = strlen(sent_message); 
	// copy a message to the shared memory
	memcpy(shm,sent_message,message_length*sizeof(char)); // now shm points to a string equals message
	// add a '\0' to the string to make it a proper one
	/*shm += 11; // move 11 steps now shm is right after the hello world thing*/
        *(shm+message_length) = '\0';
	stall_sending(shm); // stall till the receiver gives an OK response
	printf("-----------\n");
}

void reciving(char *shm){
	stall('*',shm);
	*shm = '#';
	printf("-----------\n");
	while ( *shm == '#' ){ // internal quick stall
	}
	// traverse through the string pointing to by the shared memory pointer
	
	while(*shm == '\0'){}// quick stall to prevent the following for from being neglected before sending the actual message 
	for( char *message = shm; *message != '\0' ; message++)
	{
		printf("%c", *message);
		*message = '\0'; // cleaning the buffer
	}

	printf("\n");
	*shm = ENDING_CHAR;
	printf("-----------\n");
}
void stall_sending(char *shm){
	stall(ENDING_CHAR, shm);
}

void stall (char stalling_character, char* shm){
	while(*shm != stalling_character){ // stall till the value of *shm is equal to the stalling char
	}
	*shm = '\0'; //cleaning
}
