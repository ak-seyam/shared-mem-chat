#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include"err_checking.h"
#include"messaging.h"

#define SH_BUFFER_SIZE 128
char *sender;
int main(int argc, char *argv[]){
	key_t key = 12345; // set a key for the shared resource
	int shmid = shmget(key,SH_BUFFER_SIZE,IPC_CREAT | 0666); // establishing an IPC and getting the shared memory id
	ERRCHECKER_shared_memory_getting(shmid);  // check for shared memory getting errors
	char *shm = shmat(shmid,NULL,0); // getting the shared memory pointer
	ERRCHECKER_shared_memory_atteching(shm); // check for shared memory attaching errors

	// check for arguments 
	if (argc == 1)
		sender = "server";
	else if (argc == 2)
		sender = argv[1];
	// sending and receiving
	while (1){
		char message[100];
		printf("hey %s enter the message: ",sender);
		scanf("%s",message);
		send_message(sender,message,shm);
		reciving(shm);
	}
	return 0;
}

