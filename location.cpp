//
// Created by Patrick on 2/25/2018.
//

#include "location.h"

location::location(int rowInput, int colInput) {
    row = rowInput;
    column = colInput;
}

location::location() {
    //initialize to an unreachable location for error correcting
    row = 10;
    column = 10;
}