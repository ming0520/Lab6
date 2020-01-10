
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

int main(void){
    char msg[1024];
	printf("message_send [PROMPT] Enter a text: ");
	while(fgets(msg,1024,stdin) != NULL,!feof(stdin)) { 
         printf("%s",msg);
	}

    printf("%s",msg);
    return 0;
}