#include <iostream>
#include "cclib.hh"

MyCPPClass::MyCPPClass(int x) {
    std::cout << "Constructing a MyCPPClass." << std::endl;
    this->prv = x;
}

MyCPPClass::MyCPPClass() {
    std::cout << "Constructing a MyCPPClass (no inputs)" << std::endl;
    this->prv = 0;
}

MyCPPClass::~MyCPPClass() {
    std::cout << "Destroying a MyCPPClass!" << std::endl;
}

void MyCPPClass::doVoidy() {
    std::cout << "doVoidy! prv:" << this->prv << std::endl;
}

int MyCPPClass::doInty(int x) {
    std::cout << "doInty! " << std::endl;
    return x + 10;
}

extern "C" {
CMyCPPClass newmyCPPClass(int x) {
    return reinterpret_cast<CMyCPPClass>(new MyCPPClass(x));
}

void myCPPClass_destroy(CMyCPPClass c) {
    delete reinterpret_cast<MyCPPClass*>(c);
}

void myCPPClass_doVoidy(CMyCPPClass c) {
    reinterpret_cast<MyCPPClass*>(c)->doVoidy();
}

int myCPPClass_doInty(CMyCPPClass c, int x) {
    return reinterpret_cast<MyCPPClass*>(c)->doInty(x);
}
}
