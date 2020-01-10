#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd3, retval3;
	char buffer3[] = "TESTDATA3";
	
	fd3 = open("/tmp/myfifo3",O_RDONLY);
	retval3 = read(fd3, buffer3, sizeof(buffer3));
	fflush(stdin);
	write(1, buffer3, sizeof(buffer3));
	printf("\n");	
	close(fd3);
	return 0;
}