#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXSIZE 18

void die(char *str){
    perror(str);
    exit(1);
}

int main (void){
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 2211;

    if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0){
        die("shmget");
    }

    if((shm = shmat(shmid, NULL, 0)) == (char*) - 1){
        die("shmget");
    }

    s = shm;
    char numberStr = '2';
    *s = numberStr;

    printf("[SERVER] Input: %c\n",numberStr);

    while(strcmp(shm,"READY") != 0){
        sleep(1);
    }
    printf("[SERVER] Client message: %s\n",shm);
    *shm = '*';
    sleep(3);


    for(int i = 1; i <= 10; i++){
        while(*shm == '*'){
            sleep(1);
        }
        printf("[SERVER] Client message: ");
        int num = atoi(shm);
        printf("%i\n",num);
        *shm = '*';
        
    }

    shmctl(shmid, IPC_RMID, NULL);
    exit(0);
}