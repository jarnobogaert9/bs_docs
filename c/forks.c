#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// Zolang de ouder de status van het kind proces niet leest blijft het leven
// Als ouder langer leeft en je kind is al klaar dan heb je een zombie, kind blijft wachten tot ouder zijn exit status leest
// Als kind langer leeft dan de ouder dan zal je een orpheant krijgen, parent zal gewoon vredig aflsuiten maar kind zal ineens spawnen
int main(int argc, char **argv) {
    int pid = fork();
    if (pid == 0) {
        // CHILD
        // sleep(10);
        // 0de argument is naam van het programma zelf
        char *args[] = {"sleep", "10", 0}; // tabel/array van c-strings en eindigen met 0
        execv("/usr/bin/sleep", args); // overschrijven van wat de kopie doet
        // printf("This is the child!\n", args);
        return 0;
    } else if (pid < 0) {
        perror(argv[0]);
        return 0;
    }
    // PARENT
    // Blokkerende systeem aanroep
    // Wacht tot het kind proces met PID klaar is
    waitpid(pid, NULL, 0);
    return 0;
}