#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd1, retval1;
    int fd2, retval2;
    int fd3, retval3;
	char buffer1[] = "TESTDATA1";
    char buffer2[] = "TESTDATA2";
    char buffer3[] = "TESTDATA3";
	
	fflush(stdin);
	retval1 = mkfifo("/tmp/myfifo1",0666);
	fd1 = open("/tmp/myfifo1",O_WRONLY);

    retval2 = mkfifo("/tmp/myfifo2",0666);
	fd2 = open("/tmp/myfifo2",O_WRONLY);

    retval3 = mkfifo("/tmp/myfifo3",0666);
	fd3 = open("/tmp/myfifo3",O_WRONLY);

	write(fd1,buffer1,sizeof(buffer1));
    write(fd2,buffer2,sizeof(buffer2));
    write(fd3,buffer3,sizeof(buffer3));
	close(fd1);
    close(fd2);
    close(fd3);
	return 0;
}