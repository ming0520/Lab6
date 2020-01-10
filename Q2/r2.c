#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd2, retval2;
	char buffer2[] = "TESTDATA2";
	
	fd2 = open("/tmp/myfifo2",O_RDONLY);
	retval2 = read(fd2, buffer2, sizeof(buffer2));
	fflush(stdin);
	write(1, buffer2, sizeof(buffer2));
	printf("\n");	
	close(fd2);
	return 0;
}