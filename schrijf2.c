#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
	srand(time(0));
	// Open file descriptor
  	int fd = open("./largefile", O_WRONLY|O_CREAT);
	// Check if file descriptor was opened
  	if (fd < 0) {
    		perror(argv[0]);
    		return 1;
  	}
	char buffer[1024];
	for (int i = 0; i < 10*1024; i++) {
		for (int j = 0; j < 1024; j++) {
			buffer[j] = rand() % 26 + 'a';
		}

		if (write(fd, buffer, 1024) < 0) {
			perror(argv[0]);
			return 1;
		}
	}
	// Close file descriptor
  	if (close(fd) < 0) {
		perror(argv[0]);
  		return 1;
  	}
  return 0;
}
