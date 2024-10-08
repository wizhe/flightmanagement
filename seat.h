// seat.h


#ifndef IOSTREAM_L
#define IOSTREAM_L
#include <iostream>
using namespace std;
#endif



#ifndef SEAT_H
#define SEAT_H




class Seat {
    private:
        int rowNum;
        int colNum;
        bool isAvailable;

    public:
        //ctor
        Seat();

        Seat(int ro, int co, bool stat);

        //copy-ctor
        Seat(const Seat& s);

        //dtor
        ~Seat();

        //getters
        int getRowNum() const {
            return rowNum;
        }

        int getColNum() const {
            return colNum;
        }

        bool getAvailability() const {
            return isAvailable;
        }

        //setters
        void setRowNum(int val);

        void setColNum(int val);

        void setAvailability(bool val);


        Seat& operator=(const Seat& s) {
            if (this != &s) {
                rowNum = s.rowNum;
                colNum = s.colNum;
                isAvailable = s.isAvailable;
            }
            return *this;
        }

};

#endif