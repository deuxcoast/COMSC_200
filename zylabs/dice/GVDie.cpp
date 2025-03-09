#include "GVDie.h"
#include <iostream>
using namespace std;

GVDie::GVDie() {
    myValue = -1;
}

void GVDie::Roll() {
    myValue = (rand() % 6) + 1;  // 1 to 6
}

int GVDie::GetValue() {
    return myValue;
}

// Allows dice to be compared if necessary
int GVDie::CompareTo(GVDie d) {
    return GetValue() - d.GetValue();
    ;
}
