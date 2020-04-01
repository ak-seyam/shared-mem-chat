#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include"err_checking.h"
#include"messeging.h"

#define SH_BUFFER_SIZE 128
char *sender;
int main(int argc, char *argv[]){
	key_t key = 12345;
	int shmid = shmget(key, SH_BUFFER_SIZE, 0666);
	ERRCHECKER_shared_memory_getting(shmid);
	char *shm = shmat(shmid, NULL , 0);
	ERRCHECKER_shared_memory_atteching(shm);
	if (argc == 1)
		sender = "client";
	else if (argc == 2)
		sender = argv[1];
	reciving(shm);
	send_messege(sender,"resp", shm);
	reciving(shm);

	return 0;
}

