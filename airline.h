// airline.h


#include "flight.h"

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

#ifndef ALGORITHM_L
#define ALGORITHM_L
#include <algorithm>
using namespace std;
#endif



#ifndef AIRLINE_H
#define AIRLINE_H



class Airline {
    private:
        string name;
        int numOfFlights;
        vector<Flight>* flights;

    public:
        //ctor
        Airline() ;

        //copy-ctor
        Airline(const Airline& rhs);

        //dtor
        ~Airline();

        //getters
        string getName() const;

        int getNumOfFlights() const;

        vector<Flight>* getFlights() const;

        //setters
        void setName(string val);

        void setNumOfFlights(int val);

        void setFlight(vector<Flight>* val);

        void addFlight(Flight val);

};

#endif