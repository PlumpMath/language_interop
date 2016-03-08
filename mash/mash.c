#include "DoStuff_stub.h"
#include "clib.h"
#include "rust.h"
#include "cclib-c.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    hs_init(&argc, &argv);

    // hs
    doStuff_hs(4);

    // rust
    rust_testing();

    // c (easy.)
    c_testing();

    // c++
    CMyCPPClass p = newmyCPPClass(3);
    myCPPClass_doVoidy(p);
    myCPPClass_destroy(p);


    hs_exit();
}
