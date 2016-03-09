#include <stdio.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <stdlib.h>
#include <unistd.h>
#include "clib.h"

double sinapprox(double angle) {
    return 16*angle*(3.14159265 - angle)/(49.348022 - 4*angle*(3.14159265 - angle));
}

void c_testing() {
    printf("Hello from C!");
}

void startJava() {
    pid_t pid = fork();
    if (pid == 0) {
        setpgid(0, 0);
        system("java Readfifo");
    } 
}

void quitJava() {
    FILE * f = fopen("fifo", "w");
    fprintf(f, "quit");
    fflush(f);
    fclose(f);
}

void sendHelloToJava() {
    FILE * f = fopen("fifo", "w");
    fprintf(f, "hello");
    fflush(f);
    fclose(f);
}
