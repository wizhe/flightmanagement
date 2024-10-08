// flight.h


#include "passenger.h"

#ifndef STRING_L
#define STRING_L
#include <string>
using namespace std;
#endif

#ifndef VECTOR_L
#define VECTOR_L
#include <vector>
using namespace std;
#endif

#ifndef LIMITS_L
#define LIMITS_L
#include <limits>
using namespace std;
#endif

#ifndef FSTREAM_L
#define FSTREAM_L
#include <fstream>
using namespace std;
#endif

#ifndef IOSTREAM_L
#define IOSTREAM_L
#include <iostream>
using namespace std;
#endif



#ifndef FLIGHT_H
#define FLIGHT_H




class Flight {
    private:
        string flightID;
        int rows;
        int cols;
        vector <Passenger>* passengers;
        vector <vector <Seat>>* seating;
        void setSeats();

    public:
        //ctor
        Flight();
        Flight(const string& fID, const int& ro, const int& co, const vector <Passenger>& pas);

        //copy-ctor
        Flight(const Flight& f);

        //dtor
        ~Flight();

        //getters
        string getID() const {
            return flightID;
        }

        int getRows() const {
            return rows;
        }

        int getCols() const {
            return cols;
        }

        vector <Passenger> getPass() const {
            return *passengers;
        }

        vector <vector <Seat>> getSeating() const {
            return *seating;
        }

        Seat& getSeat(int row, int col) {
            return (*seating)[row - 1][col - 1];
        }

        //setters
        void setFlightID(string val);

        void setRows(int val);

        void setCols(int val);

        void addPass(Passenger val);

        void delPass(int val);

        void menuCreatePass();

        void menuDeletePass();

        void setPassSeat(int id, int row, char col);
        
        //populate from file
        void populate_flight_from_file(const string& file_name);

        void saveData();
};

#endif