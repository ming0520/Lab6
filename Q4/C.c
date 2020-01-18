#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXSIZE 27

void die(char *str) {
	perror(str);
	exit(1);
}

int main(void){
    int shmid;
    key_t key;
    char *shm, *s;
    int valueA,valueB;

    key = 2211;
    fflush(stdin);

    if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0){
        die("shmget");
    }

    if((shm = shmat(shmid, NULL, 0)) == (char*) - 1){
        die("shmat");
    }

    valueA = atoi(shm);
    printf("%i\n", valueA);

    *shm = '*';
    while(*shm == '*'){
        sleep(1);
    }

    valueB = atoi(shm);
    printf("%i\n", valueB);

    *shm = '#';
    while(*shm != 'A'){
        sleep(1);
    }

    sprintf(shm, "%i", valueA+valueB);
        
    printf("\n");
    exit(0);
}