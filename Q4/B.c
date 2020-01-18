#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXSIZE 27

void die(char *str){
    perror(str);
    exit(1);
}

int main (void){
    char number[2];
    int shmid;
    key_t key;
    char *shm, *s;
    int value;

    key = 2211;

    if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0){
        die("shmget");
    }

    if((shm = shmat(shmid, NULL, 0)) == (char*) - 1){
        die("shmat");
    }

    while(*shm != '*'){
        sleep(1);
    }
    *shm = '1';

    while(*shm == 'A'){
        sleep(1);
    }

    value = atoi(shm);
    printf("value A+B: %i\n",value);
    

    exit(0);
}