#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	pid_t pid = fork();
	int status;
	if (pid == 0) {
		printf("In child process, exegguting hellowait.c\n");
		system("gcc hellowait.c -o hellowait.o");
		system("./hellowait.o");
		sleep(2);
	} else {
		while(wait(&status) != pid);
		printf("Parent process here...\n");
	}
	return 0;
}