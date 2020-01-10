#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define MAXSIZE 18

void die(char *str){
    perror(str);
    exit(1);
}

int main (void){
    int shmid;
    key_t key;
    char *shm, *s;

    key = 2211;
    fflush(stdin);

    if((shmid = shmget(key,MAXSIZE, IPC_CREAT | 0666)) < 0){
        die("shmget");
    }

    if((shm = shmat(shmid,NULL, 0)) == (char*) - 1){
        die("shmmat");
    }

    int num = 0;
    char ready[5] = "READY";

    num = atoi(shm);
    printf("[CLIENT] Output: %i\n",num);

    s = shm;
    for(int i = 0; i < 5; i++){
        *s++ = ready[i];
    }

    for(int i = 1; i <= 10; i++){
        while(*shm != '*'){
            sleep(1);
        }

        int counter = 0;
        int n = num;
        char x[10];

        n = num * i;
        do{
            counter++;
            n /= 10;
        }while(n > 0);

        n = num * i;
        sprintf(x,"%i",n);
        s = shm;
        for(int i = 0; i < counter; i++){
            *s++ = x[i];
        }
        printf("[CLIENT] Input: %i\n",n);

    }

    shmctl(shmid, IPC_RMID, NULL);
    exit(0);
}