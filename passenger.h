// passenger.h


#include "seat.h"

#ifndef IOMANIP_L
#define IOMANIP_L
#include <iomanip>
using namespace std;
#endif

#ifndef STRING_L
#define STRING_L
#include <string>
using namespace std;
#endif

#ifndef IOSTREAM_L
#define IOSTREAM_L
#include <iostream>
using namespace std;
#endif



#ifndef PASSENGER_H
#define PASSENGER_H




class Passenger {
    private:
        int ID;
        string fname;
        string lname;
        int seatRow;
        int seatCol;
        string phone;

    public:
        //ctor
        Passenger();
        
        //copy-ctor
        Passenger(const Passenger& rhs);

        //dtor
        ~Passenger() {}

        //getters
        int getID() const {
            return ID;
        }

        string getFname() const {
            return fname;
        }

        string getLname() const {
            return lname;
        }

        int getSeatRow() const {
            return seatRow;
        }

        int getSeatCol() const {
            return seatCol;
        }

        string getPhone() const {
            return phone;
        }

        //setters
        void setID(int val) {
            ID = val;
        }

        void setFname(string val) {
            fname = val;
        }

        void setLname(string val) {
            lname = val;
        }

        void setSeat(int row, int col) {
            seatRow = row;
            seatCol = col;
        }

        void setPhone(const string& val) {
            phone = val;
        }
        
        Passenger& operator=(const Passenger& rhs);

        bool operator==(const Passenger& rhs) const;

        void print_info();

};

#endif