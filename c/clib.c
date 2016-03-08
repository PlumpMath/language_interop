#include <stdio.h>
#include "clib.h"

double sinapprox(double angle) {
    return 16*angle*(3.14159265 - angle)/(49.348022 - 4*angle*(3.14159265 - angle));
}

void c_testing() {
    printf("Hello from C!");
}
