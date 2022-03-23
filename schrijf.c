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
	for (int i = 0; i < 10*1024*1024; i++) {

		// Generate random letter between a and b
		char ch = rand() % 26 + 'a';

		if (write(fd, &ch, 1) < 0) {
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
