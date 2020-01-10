#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd1, retval1;
	char buffer1[] = "TESTDATA1";
	
	fd1 = open("/tmp/myfifo1",O_RDONLY);
	retval1 = read(fd1, buffer1, sizeof(buffer1));
	fflush(stdin);
	write(1, buffer1, sizeof(buffer1));
	printf("\n");	
	close(fd1);
	return 0;
}