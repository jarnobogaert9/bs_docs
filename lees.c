#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int main(int argc, char **argv) {
	// Open file descriptor
  	int fd = open("./largefile", O_RDONLY); 
	// Check if file descriptor was opened
  	if (fd < 0) {
    		perror(argv[0]);
    		return 1;
  	}
	char buffer[8129];

	for (int i = 1; i <= 8192; i<<=1) {
		double start = clock();
		if (lseek(fd, 0, SEEK_SET)<0) {
			perror(argv[0]);
			return 1;
		}
		int n = read(fd, buffer, i);
		// Read geeft 0 terug wanneer we EOF tegenkomen
		while (n > 0) {	
			n = read(fd, buffer, i);
		}
		if (n < 0) {
			perror(argv[0]);
			return 1;
		}
		printf("BUF_SIZE=%5d Time=%10.2f\n", i, (clock()-start)/CLOCKS_PER_SEC);
	}

	// Close file descriptor
  	if (close(fd) < 0) {
		perror(argv[0]);
  		return 1;
  	}
  return 0;
}
