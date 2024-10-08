// passenger.cpp

#include "passenger.h"


Passenger::Passenger() : 
    ID(0), fname(""), lname(""), seatRow(0), seatCol(0), phone("") {}


Passenger::Passenger(const Passenger& rhs) : 
    ID(rhs.ID), fname(rhs.fname), lname(rhs.lname), seatRow(rhs.seatRow), seatCol(rhs.seatCol), phone(rhs.phone) {}


Passenger& Passenger::operator=(const Passenger& rhs) {
    // checks if it's trying to assign itself to itself
    if (this != &rhs) {
        ID = rhs.ID;
        fname = rhs.fname;
        lname = rhs.lname;
        phone = rhs.phone;
        seatRow = rhs.seatRow;
        seatCol = rhs.seatCol;
    }
    return *this;
}


bool Passenger::operator==(const Passenger& rhs) const {
             return (ID == rhs.ID && fname == rhs.fname && lname == rhs.lname && phone == rhs.phone);
        }


void Passenger::print_info() {
    cout<< setw(20) << left << fname;
    cout<< setw(20) << left << lname;
    cout<< setw(20) << left << phone;
    cout<< setw(8) << left << seatRow;
    cout<< setw(8) << left << char(seatCol + 'A' - 1);  // changes column number into letter
            cout<< setw(8) << left << ID;
}

