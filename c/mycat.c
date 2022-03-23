#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
int main(int argc, char **argv) {
    int i;
    // 8KB - 8129 bytes
    unsigned char buffer[BUFSIZ]; // BUFSIZ is de meest optimale buffer grootte

    if (argc == 1) {
        int n = read(0, buffer, BUFSIZ); // how many bytes
            while (n > 0) {
                n = write(1, buffer, n); // we know how many bytes due read
                if (n < 0) {
                    perror(argv[i]);
                    return 1;
                }
                n = read(0, buffer, BUFSIZ);
            }
            if (n < 0) {
                perror(argv[i]);
                return 1;
            }
    } else {
        for (i=1; i<argc; i++) {
            // Check for '-'
            if (strcmp(argv[i], "-") == 0) {
                int n = read(0, buffer, BUFSIZ); // how many bytes
                while (n > 0) {
                    n = write(1, buffer, n); // we know how many bytes due read
                    if (n < 0) {
                        perror(argv[i]);
                        continue;
                    }
                    n = read(0, buffer, BUFSIZ);
                }
                if (n < 0) {
                    perror(argv[i]);
                    continue;
                }
            } else {
                int fd = open(argv[i], O_RDONLY);
                if (fd < 0) {
                    perror(argv[i]);
                    continue;
                }

                int n = read(fd, buffer, BUFSIZ); // how many bytes
                while (n > 0) {
                    n = write(1, buffer, n); // we know how many bytes due read
                    if (n < 0) {
                        perror(argv[i]);
                        continue;
                    }
                    n = read(fd, buffer, BUFSIZ);
                }
                
                if (n < 0) {
                    perror(argv[i]);
                    continue;
                }

                if (close(fd) < 0) {
                    perror(argv[i]);
                    continue;
                }
            }
        }
    }
    
    return 0;
}