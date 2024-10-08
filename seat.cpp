// seat.cpp


#include "seat.h"




Seat::Seat() :
    rowNum(0), colNum(0), isAvailable(true) {}


Seat::Seat(int ro, int co, bool avail) :
    rowNum(ro), colNum(co) {setAvailability(avail);}


Seat::Seat(const Seat& s) :
    rowNum(s.rowNum), colNum(s.colNum), isAvailable(s.isAvailable) {}


Seat::~Seat() {}


void Seat::setRowNum(int val) {
    rowNum = val;
}


void Seat::setColNum(int val) {
    colNum = val;
}


void Seat::setAvailability(bool val) {
    if (val == true) {
        isAvailable = true;
    }
    else if (val == false){
        isAvailable = false;
    }
}

