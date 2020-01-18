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
    char number[3];
    int shmid;
    key_t key;
    char *shm, *s,*ptr;
    int value;

    key = 2211;

    if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0){
        die("shmget");
    }

    if((shm = shmat(shmid, NULL, 0)) == (char*) - 1){
        die("shmat");
    }

    s = shm;

    number[0] = '0';
    *shm = number[0];
    value = atoi(shm);

    // while(*shm == '*' || (strcmp(shm,number) == 0)){
    //     printf("Differ: %i shm: ", strcmp(shm,number));
    //     puts(shm);
    //     sleep(1);
    // }

    // value = atoi(shm);
    // printf("value: %i\n", value);
    // sprintf(number,"%i",value);
    // printf("number: ");
    // puts(number);
    while(strcmp(shm,number) == 0){
        sleep(1);
    }

    while(*shm == '*'){
        sleep(1);
    }

    value = atoi(shm);
    printf("value: %i\n", value);

    while(*shm != '#')
        sleep(1);

    *shm = 'A';
    

    exit(0);
}